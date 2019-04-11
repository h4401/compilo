#include "Visitor.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


Visitor::Visitor()
{
    offset = 0;
    output.open("asm.s");
    error = false;
    firstMult = true;
}

Visitor::~Visitor()
{
    output.close();
}


//--------------------- Visiteur Programme --------------------------//
antlrcpp::Any Visitor::visitProg(GrammarParser::ProgContext* ctx)
{

    Program* prog = new Program();
    for(auto i: ctx->func()){
        prog->addFunction(visit(i));
    }
    return prog;
}

//--------------------- Visiteur Fonction --------------------------//
antlrcpp::Any Visitor::visitFunc(GrammarParser::FuncContext* ctx)
{
    this->offset = 0;
    table = new SymbolTable();
    string name = ctx->ID(0)->getText();
    vector <DeclVar*> vecDecl;

    for(int i = ctx->ID().size()-1;i>0;i--){
        offset -= 4;
        string nameVar = ctx->ID(i)->getText();
        Variable* var = new Variable(nameVar,offset,false);
        var->setType(INT);
        table->insert(make_pair(nameVar,var));
        DeclVar * declvar = new DeclVar(nameVar,var->getType());
        vecDecl.push_back(declvar);
    }
    Block* block = visit(ctx->block());
    Type type = visit(ctx->type(0));
    Function* func = new Function(table, name,block,type,vecDecl);

    return func;
}

//--------------------- Visiteur Block --------------------------//
antlrcpp::Any Visitor::visitBlock(GrammarParser::BlockContext* ctx)
{

    Block* block = new Block();

    for (unsigned int i = 0; i < ctx->declvar().size(); i++) {
	std::vector<DeclVar*> declarations = visit(ctx->declvar()[i]);
	for(auto d : declarations){
        	block->addDeclaration(d);
	}
    }
    for (unsigned int i = 0; i < ctx->statement().size(); i++) {
         	Statement * s = visit(ctx->statement()[i]);
            	block->addStatement(s);
    }
    return block;
}

//--------------------- Visiteur Instructions --------------------------//

// Retour fonction
antlrcpp::Any Visitor::visitReturn(GrammarParser::ReturnContext* ctx)
{

    Expression * expr = visit(ctx->ret()->expr());
    Return* ret = new Return(expr);
    return dynamic_cast<Statement *>(ret);
}

//Definition Variable
antlrcpp::Any Visitor::visitDefvariable(GrammarParser::DefvariableContext* ctx)
{
    string name = ctx->defvar()->ID()->getText();
    std::unordered_map<std::string, Variable*>::const_iterator it = table->find(name);
    if (it == table->end()) {
        int line = ctx->getStart()->getLine();
        cerr << "[-] Error (Line " << to_string(line) << "): Undeclared variable " << name << endl;
        error = true;
        return -1;
    }
    else {
        Expression* expr = visit(ctx->defvar()->expr());
        it->second->setInitialized();
        it->second->setValeur(to_string(expr->getValeur()));

        DefVar* defvar = new DefVar(it->second, expr);
        return dynamic_cast<Statement *>(defvar);
    }
}

//Execution de fonction
antlrcpp::Any Visitor::visitExfuncStatement(GrammarParser::ExfuncStatementContext* ctx)
{
    string name = ctx->execfunc()->ID()->getText();
    Param * param = visit(ctx->execfunc()->param());
    ExecFunc* exe = new ExecFunc(name, param);
    return dynamic_cast<Statement *>(exe);   
}


//Expression 
antlrcpp::Any Visitor::visitExprStatement(GrammarParser::ExprStatementContext* ctx)
{
    Expression * expr = visit(ctx->expr());
    return dynamic_cast<Statement *>(expr);
}

//If
antlrcpp::Any Visitor::visitIfStatement(GrammarParser::IfStatementContext* ctx)
{
    If* anIf = visit(ctx->insif());
    return dynamic_cast<Statement*>(anIf);
}

//--------------------- Visiteur If --------------------------//
antlrcpp::Any Visitor::visitInsif(GrammarParser::InsifContext* ctx)
{
    Expression* condition = visit(ctx->expr());
    Block* block = visit(ctx->block());
    If* anIf = new If(condition, block);
    if(ctx->inselse() != nullptr){
        anIf->setElse(visit(ctx->inselse()));
    }
    return anIf;
}

//--------------------- Visiteur Else --------------------------//
antlrcpp::Any Visitor::visitInselse(GrammarParser::InselseContext* ctx)
{
    Block * block = visit(ctx->block());
    Else* anElse = new Else (block);
    return anElse;
}


//--------------------- Visiteur Expression --------------------------//
//Constante
antlrcpp::Any Visitor::visitConst(GrammarParser::ConstContext* ctx)
{

    Expression* exprC = new ExpressionConst();
    exprC->setValeur((int)stoi(ctx->INT()->getText()));
    return dynamic_cast<Expression *>(exprC);
}

//Variable
antlrcpp::Any Visitor::visitVar(GrammarParser::VarContext* ctx)
{
    string name = ctx->ID()->getText();
    std::unordered_map<std::string, Variable*>::const_iterator it = table->find(name);
    int line = ctx->getStart()->getLine();
    if (it == table->end()) {
        cerr << "[-] Error (Line " << to_string(line) << "): Undefined variable " << name << endl;
        error = true;
        return -1;
    }
    else if (!it->second->isInitialized()) {
        cerr << "[!] Warning (Line " << to_string(line) << "): Uninitialized variable " << name << endl;
    }
    Variable * var = it->second;
    //expr->setOffset(it->second->getOffset());
    //expr->setType(VAR);
    return dynamic_cast<Expression *>(var);
}

//Operation +
antlrcpp::Any Visitor::visitPlus(GrammarParser::PlusContext* ctx)
{

    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* ePlus = new ExprOperationBinary(el, er, "+");
    ePlus->setType(EXPRBINAIRE);
    ePlus->setOffset(offset);
    return dynamic_cast<Expression*>(ePlus);
}

//Operation -
antlrcpp::Any Visitor::visitMinus(GrammarParser::MinusContext* ctx)
{
    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eMinus = new ExprOperationBinary(el, er, "-");
    eMinus->setType(EXPRBINAIRE);
    eMinus->setOffset(offset);
    return dynamic_cast<Expression*>(eMinus);
}

//Operation *
antlrcpp::Any Visitor::visitMult(GrammarParser::MultContext* ctx)
{

    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eMult = new ExprOperationBinary(el, er, "*");
    eMult->setType(EXPRBINAIRE);
    eMult->setOffset(offset);
    return dynamic_cast<Expression*>(eMult);
}

//Operation /
antlrcpp::Any Visitor::visitDiv(GrammarParser::DivContext* ctx)
{
    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eDiv = new ExprOperationBinary(el, er, "/");
    eDiv->setType(EXPRBINAIRE);
    eDiv->setOffset(offset);
   return dynamic_cast<Expression*>(eDiv);
}

//Operation =
antlrcpp::Any Visitor::visitEq(GrammarParser::EqContext* ctx){
    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eEq = new ExprOperationBinary(el, er, "==");
    eEq->setType(EXPRBINAIRE);
    eEq->setOffset(offset);
    return dynamic_cast<Expression*>(eEq);

}

//Operation >
antlrcpp::Any Visitor::visitGt(GrammarParser::GtContext* ctx){
    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eGt = new ExprOperationBinary(el, er, ">");
    eGt->setType(EXPRBINAIRE);
    eGt->setOffset(offset);
    return dynamic_cast<Expression*>(eGt);
    
}

//Operation <
antlrcpp::Any Visitor::visitLt(GrammarParser::LtContext* ctx){
    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eLt = new ExprOperationBinary(el, er, "<");
    eLt->setType(EXPRBINAIRE);
    eLt->setOffset(offset);
    return dynamic_cast<Expression*>(eLt);
    
}

//Operation <=
antlrcpp::Any Visitor::visitLte(GrammarParser::LteContext* ctx){
    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eLte = new ExprOperationBinary(el, er, "<=");
    eLte->setType(EXPRBINAIRE);
    eLte->setOffset(offset);
    return dynamic_cast<Expression*>(eLte);
    
}

//Operation >=
antlrcpp::Any Visitor::visitGte(GrammarParser::GteContext* ctx){
    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eGte = new ExprOperationBinary(el, er, ">=");
    eGte->setType(EXPRBINAIRE);
    eGte->setOffset(offset);
    return dynamic_cast<Expression*>(eGte);
    
}

//Operation !=
antlrcpp::Any Visitor::visitNeq(GrammarParser::NeqContext* ctx){
    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eNeq = new ExprOperationBinary(el, er, "!=");
    eNeq->setType(EXPRBINAIRE);
    eNeq->setOffset(offset);
    return dynamic_cast<Expression*>(eNeq);
    
}

//Parenthèses
antlrcpp::Any Visitor::visitPar(GrammarParser::ParContext* ctx)
{
    Expression* expr = visit(ctx->expr());
    ExprPar* exprPar = new ExprPar(expr);
    return dynamic_cast<Expression *>(exprPar);
}
//Execution Fonction comme Expression
antlrcpp::Any Visitor::visitExfunc(GrammarParser::ExfuncContext* ctx)
{
    string name = ctx->execfunc()->ID()->getText();

    Param* p = visit(ctx->execfunc()->param());
    ExecFunc* exe = new ExecFunc(name, p);
    return dynamic_cast<Expression *>(exe);
}

//--------------------- Visiteur Parametres fonction --------------------------//
//parametres non vide
antlrcpp::Any Visitor::visitParamFonction(GrammarParser::ParamFonctionContext* ctx)
{
    vector<Expression*> params;
    for(auto i : ctx->expr()){
	params.push_back(visit(i));
    }
    Param *p = new Param(params);

    return p;
}

//parametres vide
antlrcpp::Any Visitor::visitParamVide(GrammarParser::ParamVideContext *ctx) {
    
    vector<Expression*> params;
    Param *p = new Param(params);
    
    return p;
}

//--------------------- Visiteur Type --------------------------//
antlrcpp::Any Visitor::visitTypeint(GrammarParser::TypeintContext* ctx)
{
    return INT;
}

//--------------------- Visiteur Declaration de variable --------------------------//
antlrcpp::Any Visitor::visitDeclvar(GrammarParser::DeclvarContext* ctx)
{
    std::vector<DeclVar*> declarations;
    Type type = visit(ctx->type());
    for (unsigned int i = 0; i < ctx->ID().size(); i++) {
        string name = ctx->ID(i)->getText();
        std::unordered_map<std::string, Variable*>::const_iterator it = table->find(name);
        if (it != table->end()) {
            int line = ctx->getStart()->getLine();
            cerr << "[-] Error (Line " << line << ") Variable " << name << " is already declared in this scope" << endl;
            error = true;
            return -1;
        }
        else {
            offset -= 4;
            Variable* v = new Variable(name, offset, false);
            v->setType(type);
	    if ( GrammarParser::InitContext * init = dynamic_cast<GrammarParser::InitContext*>(ctx->optinit(i)))
	    {
		ExpressionConst * exprC = visit(ctx->optinit(i));
		v->setValeur(to_string(exprC->getValeur()));
		v->setInitialized();
	    }
            table->insert(std::make_pair(name, v));
	    declarations.push_back(new DeclVar(name, type));
        }
    }
    return declarations;
    
}

//--------------------- Visiteur initialisation --------------------------//
//pas d'initialisation
antlrcpp::Any Visitor::visitInitvide(GrammarParser::InitvideContext* ctx)
{
    return nullptr;
}
//initialisation
antlrcpp::Any Visitor::visitInit(GrammarParser::InitContext* ctx)
{
    ExpressionConst* exprC = new ExpressionConst();
    exprC->setValeur((int)stoi(ctx->INT()->getText()));
    return exprC;
}

//--------------------- Affichage table de symbole --------------------------//
void Visitor::printTable(){
    for (auto it : *table){
        cout<<"table: "<<endl;
        std::cout << "first: " << it.first << "; second: " << it.second << std::endl;
    }
}
