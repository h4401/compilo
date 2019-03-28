//
//  Calc.h
//  
//
//  Created by yanghua on 2019/3/10.
//
#include "Calc.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Variable.h"
#include "Type.h"

using namespace std;

Calc::Calc(){
    offset = 0;
    output.open("asm.s");
    error = false;
    firstMult = true;
}

Calc::~Calc(){
    output.close();
}

// PROG
antlrcpp::Any Calc::visitProg(GrammarParser::ProgContext *ctx) {
    
    return visit(ctx->func(0));
}

// FUNC
antlrcpp::Any Calc::visitFunc(GrammarParser::FuncContext *ctx) {
    output << ".file \"2.c\""<< endl;
    output << ".text" << endl;
    output << ".global main" << endl;
    output << ".type main, @function" << endl;
    output << "main:" << endl;
    output << "pushq  %rbp" << endl;;
    output << "movq %rsp, %rbp" << endl;
    return visit(ctx->block());
}

//BLOCK    
antlrcpp::Any Calc::visitBlock(GrammarParser::BlockContext *ctx) {
    for (unsigned int i = 0; i<ctx->declvar().size(); i++ )
    {
        visit(ctx->declvar()[i]);
        
    }
    for (unsigned int i = 0; i<ctx->statement().size(); i++ )
    {
        if (GrammarParser::ReturnContext* ret = dynamic_cast<GrammarParser::ReturnContext *>(ctx->statement()[i]))
        {
	    Expression * expr = visit(ret);
            return(expr->getOffset());
        }
        else
        {
            visit(ctx->statement()[i]);
        }
        
    }
    return -1;
}

// STATEMENT
antlrcpp::Any Calc::visitReturn(GrammarParser::ReturnContext *ctx) {
    Expression* expr = visit(ctx->ret()->expr());
    output << "movl "<<  to_string(expr->getOffset()) << "(%rbp), eax"<<endl;
    output << "popq %rbp" << endl;
    output << "ret" << endl;
    return expr;
}

//DefVar
antlrcpp::Any Calc::visitDefvariable(GrammarParser::DefvariableContext *ctx) {
    string name = ctx -> defvar()-> ID()-> getText();
    std::unordered_map<std::string,Variable *>::const_iterator it = table.find(name);
    if (it == table.end()){
        int line = ctx -> getStart() -> getLine();
        cerr << "[-] Error (Line " << to_string(line) << "): Undeclared variable " << name << endl;
        error = true;
        return -1;
    }
    else
    {
        Expression* expr = visit(ctx -> defvar()-> expr());
        //        int value = visit(ctx -> defvar()-> expr());
        it->second->setInitialized();
        it->second->setValeur(to_string(expr->getValeur()));
        if(expr->getType() == EXPRBINAIRE){
            output << "movl "<< to_string(expr->getOffset())  << "(%rbp), "<<to_string(it->second->getOffset())<< "(%rbp)" << endl;
	}
        else if(expr->getType() == CONST){
            output << "movl $"<<to_string(expr->getValeur())<< ", "<<to_string(it->second->getOffset())<< "(%rbp)" << endl;
	}
	else if(expr->getType() == VAR){
	    output << "movl "<<to_string(expr->getOffset())<< "(%rbp), eax" << endl;
	    output << "movl eax, "<<to_string(it->second->getOffset())<< "(%rbp)" << endl;
	}
        return expr;
    }
    
}

//EXPR
antlrcpp::Any Calc::visitConst(GrammarParser::ConstContext *ctx) {
    Expression* expr;
    expr = new Expression();
    expr->setValeur((int) stoi(ctx->INT()->getText()));
    expr->setType(CONST);
    return expr;
}

antlrcpp::Any Calc::visitVar(GrammarParser::VarContext *ctx) {
    Expression* expr;
    expr = new Expression();
    string name = ctx -> ID() -> getText();
    std::unordered_map<std::string,Variable *>::const_iterator it = table.find(name);
    int line  = ctx -> getStart() -> getLine();
    if (it == table.end()){
        cerr << "[-] Error (Line " << to_string(line) << "): Undefined variable " << name << endl;
        error = true;
        return -1;
    }
    else if(!it -> second->isInitialized()){
        cerr << "[!] Warning (Line " << to_string(line) << "): Uninitialized variable " << name << endl;
    }
    expr->setOffset(it-> second -> getOffset());
    expr->setType(VAR);
    return expr;
}

antlrcpp::Any Calc::visitPlus(GrammarParser::PlusContext *ctx) {
    
    Expression* el = visit(ctx -> expr(0));
    Expression* er = visit(ctx -> expr(1));
    offset -= 4 ;
    ExprOperationBinary* ePlus = new ExprOperationBinary(el,er,'+');
    ePlus->generateAsm(output, offset);
    ePlus->setType(EXPRBINAIRE);
    ePlus->setOffset(offset);
    return dynamic_cast<Expression*> (ePlus);
}

antlrcpp::Any Calc::visitMinus(GrammarParser::MinusContext *ctx) {
    Expression* el = visit(ctx -> expr(0));
    Expression* er = visit(ctx -> expr(1));
    offset -= 4 ;
    ExprOperationBinary* eMinus = new ExprOperationBinary(el,er,'-');
    eMinus->generateAsm(output, offset);
    eMinus->setType(EXPRBINAIRE);
    eMinus->setOffset(offset);
    return dynamic_cast<Expression*> (eMinus);
}


antlrcpp::Any Calc::visitMult(GrammarParser::MultContext *ctx) {
    
    Expression* el = visit(ctx -> expr(0));
    Expression* er = visit(ctx -> expr(1));
    offset -= 4 ;
    ExprOperationBinary* eMult = new ExprOperationBinary(el,er,'*');
    eMult->generateAsm(output, offset);
    eMult->setType(EXPRBINAIRE);
    eMult->setOffset(offset);
    return dynamic_cast<Expression*> (eMult);

}

antlrcpp::Any Calc::visitDiv(GrammarParser::DivContext *ctx) {
    Expression* el = visit(ctx -> expr(0));
    Expression* er = visit(ctx -> expr(1));
    offset -= 4 ;
    ExprOperationBinary* eDiv = new ExprOperationBinary(el,er,'/');
    eDiv->generateAsm(output, offset);
    eDiv->setType(EXPRBINAIRE);
    eDiv->setOffset(offset);
    return dynamic_cast<Expression*> (eDiv);
}

antlrcpp::Any Calc::visitPar(GrammarParser::ParContext *ctx) {
    Expression* expr;
    expr = new Expression();
    return expr;
}

antlrcpp::Any Calc::visitExfunc(GrammarParser::ExfuncContext *ctx) {
    Expression* expr;
    expr = new Expression();
    return expr;
    
}

//TYPE
antlrcpp::Any Calc::visitTypeint(GrammarParser::TypeintContext *ctx) {
    //TODO
    return 0;
}

//DECLVAR
antlrcpp::Any Calc::visitDeclvar(GrammarParser::DeclvarContext *ctx) {
    
    for(unsigned int i = 0; i < ctx -> ID().size(); i++)
    {
        string name = ctx -> ID(i)->getText();
        std::unordered_map<std::string,Variable *>::const_iterator it = table.find(name);
        if (it != table.end()){
            int line = ctx -> getStart() -> getLine();
            cerr << "[-] Error (Line " << line << ") Variable " << name << " is already declared in this scope" << endl;
            error = true;
            return -1;
        }
        else
        {
            offset -=4;
            Variable * v = new Variable(name, offset, false);
            table.insert(std::make_pair(name, v));
        }
    }
    return 0;
}

//OPTINIT
antlrcpp::Any Calc::visitInitvide(GrammarParser::InitvideContext *ctx) {
    //TODO
    return 0;
}


