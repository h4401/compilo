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

unordered_map<string,Variable*> Visitor::getSymbolTable(){
    return this->table;
}

// PROG
antlrcpp::Any Visitor::visitProg(GrammarParser::ProgContext* ctx)
{

    Program* prog = new Program();
    for(auto i: ctx->func()){
        prog->addFunction(visit(i));
    }
    return prog;
}

// FUNC
antlrcpp::Any Visitor::visitFunc(GrammarParser::FuncContext* ctx)
{

    string name = ctx->ID(0)->getText();
    Block* block = visit(ctx->block());
    Type type = visit(ctx->type(0));
    //    output << ".file \"2.c\"" << endl;
//    output << ".text" << endl;
//    output << ".global main" << endl;
//    output << ".type main, @function" << endl;
//    output << "main:" << endl;
//    output << "pushq  %rbp" << endl;
//    output << "movq %rsp, %rbp" << endl;
    Function* func = new Function(name,block,type);

    return func;
}

//BLOCK
antlrcpp::Any Visitor::visitBlock(GrammarParser::BlockContext* ctx)
{

    Block* block = new Block();

    for (unsigned int i = 0; i < ctx->declvar().size(); i++) {
        block->addDeclaration(visit(ctx->declvar()[i]));
    }
    for (unsigned int i = 0; i < ctx->statement().size(); i++) {
        if (GrammarParser::ReturnContext* ret = dynamic_cast<GrammarParser::ReturnContext*>(ctx->statement()[i])) {
            block->addStatement(visit(ctx->statement()[i]));
            return (block);
        }
        else {
            
            block->addStatement(visit(ctx->statement()[i]));
        }
    }
    return block;
}

// STATEMENT
antlrcpp::Any Visitor::visitReturn(GrammarParser::ReturnContext* ctx)
{

    Expression * expr = visit(ctx->ret()->expr());
    Return* ret = new Return(expr);
    
//    if(expr->getType() == VAR)
//    output << "movl " << to_string(expr->getOffset()) << "(%rbp), (%eax)" << endl;
//    else if(expr->getType() == CONST)
//    output << "movl $" << to_string(expr->getValeur()) << ", (%eax)" << endl;
//
//    output << "popq %rbp" << endl;
//    output << "ret" << endl;
    return ret;
}

//DefVar
antlrcpp::Any Visitor::visitDefvariable(GrammarParser::DefvariableContext* ctx)
{
    string name = ctx->defvar()->ID()->getText();
    std::unordered_map<std::string, Variable*>::const_iterator it = table.find(name);
    if (it == table.end()) {
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
        //        int value = visit(ctx -> defvar()-> expr());
//                if (expr->getType() == EXPRBINAIRE) {
//            output << "movl " << to_string(expr->getOffset()) << "(%rbp), (%eax)" << endl;
//            output << "movl (%eax), " << to_string(it->second->getOffset()) << "(%rbp)" << endl;
//        }
//        else if (expr->getType() == CONST) {
//            output << "movl $" << to_string(expr->getValeur()) << ", " << to_string(it->second->getOffset()) << "(%rbp)" << endl;
//        }
//        else if (expr->getType() == VAR) {
//            output << "movl " << to_string(expr->getOffset()) << "(%rbp), (%eax)" << endl;
//            output << "movl (%eax), " << to_string(it->second->getOffset()) << "(%rbp)" << endl;
//        }
        return defvar;
    }
}

//EXPR
antlrcpp::Any Visitor::visitConst(GrammarParser::ConstContext* ctx)
{

    Expression* exprC = new ExpressionConst();
    exprC->setValeur((int)stoi(ctx->INT()->getText()));
    return exprC;
}

antlrcpp::Any Visitor::visitVar(GrammarParser::VarContext* ctx)
{
    Expression* expr;
    expr = new Expression();
    string name = ctx->ID()->getText();
    std::unordered_map<std::string, Variable*>::const_iterator it = table.find(name);
    int line = ctx->getStart()->getLine();
    if (it == table.end()) {
        cerr << "[-] Error (Line " << to_string(line) << "): Undefined variable " << name << endl;
        error = true;
        return -1;
    }
    else if (!it->second->isInitialized()) {
        cerr << "[!] Warning (Line " << to_string(line) << "): Uninitialized variable " << name << endl;
    }
    expr->setOffset(it->second->getOffset());
    expr->setType(VAR);
    return expr;
}

antlrcpp::Any Visitor::visitPlus(GrammarParser::PlusContext* ctx)
{

    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* ePlus = new ExprOperationBinary(el, er, '+');
    ePlus->generateAsm(output, offset);
    ePlus->setType(EXPRBINAIRE);
    ePlus->setOffset(offset);
    return dynamic_cast<Expression*>(ePlus);
}

antlrcpp::Any Visitor::visitMinus(GrammarParser::MinusContext* ctx)
{
    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eMinus = new ExprOperationBinary(el, er, '-');
    eMinus->generateAsm(output, offset);
    eMinus->setType(EXPRBINAIRE);
    eMinus->setOffset(offset);
    return dynamic_cast<Expression*>(eMinus);
}

antlrcpp::Any Visitor::visitMult(GrammarParser::MultContext* ctx)
{

    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eMult = new ExprOperationBinary(el, er, '*');
    eMult->generateAsm(output, offset);
    eMult->setType(EXPRBINAIRE);
    eMult->setOffset(offset);
    return dynamic_cast<Expression*>(eMult);
}

antlrcpp::Any Visitor::visitDiv(GrammarParser::DivContext* ctx)
{
    Expression* el = visit(ctx->expr(0));
    Expression* er = visit(ctx->expr(1));
    offset -= 4;
    ExprOperationBinary* eDiv = new ExprOperationBinary(el, er, '/');
    eDiv->generateAsm(output, offset);
    eDiv->setType(EXPRBINAIRE);
    eDiv->setOffset(offset);
    return dynamic_cast<Expression*>(eDiv);
}

antlrcpp::Any Visitor::visitPar(GrammarParser::ParContext* ctx)
{
    Expression* expr;
    expr = new Expression();
    return expr;
}

antlrcpp::Any Visitor::visitExfunc(GrammarParser::ExfuncContext* ctx)
{
    Expression* expr;
    expr = new Expression();
    return expr;
}

//TYPE
antlrcpp::Any Visitor::visitTypeint(GrammarParser::TypeintContext* ctx)
{

    
    return INT;
}

//DECLVAR
antlrcpp::Any Visitor::visitDeclvar(GrammarParser::DeclvarContext* ctx)
{

    for (unsigned int i = 0; i < ctx->ID().size(); i++) {
        string name = ctx->ID(i)->getText();
        std::unordered_map<std::string, Variable*>::const_iterator it = table.find(name);
        if (it != table.end()) {
            int line = ctx->getStart()->getLine();
            cerr << "[-] Error (Line " << line << ") Variable " << name << " is already declared in this scope" << endl;
            error = true;
            return -1;
        }
        else {
            offset -= 4;
            Variable* v = new Variable(name, offset, false);
            table.insert(std::make_pair(name, v));
        }
    }
    return 0;
}

//OPTINIT
antlrcpp::Any Visitor::visitInitvide(GrammarParser::InitvideContext* ctx)
{
    //TODO
    return 0;
}

