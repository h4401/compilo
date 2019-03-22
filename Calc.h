//
//  Calc.h
//  
//
//  Created by yanghua on 2019/3/10.
//

#pragma once
#include "antlr4-runtime.h"
#include "GrammarBaseVisitor.h"

using namespace std;

class Calc: public GrammarBaseVisitor {
public:

// PROG
        antlrcpp::Any visitProg(GrammarParser::ProgContext *ctx) override{
        //TODO        
	return 0;
    }
    
// FUNC
        antlrcpp::Any visitFunc(GrammarParser::FuncContext *ctx) override{
	//TODO        
	return 0;
    }

//BLOCK    
        antlrcpp::Any visitBlock(GrammarParser::BlockContext *ctx) override{
        //TODO
	return 0;
    }
    
// STATEMENT
        antlrcpp::Any visitReturn(GrammarParser::ReturnContext *ctx) override{
        //TODO
	return 0;
    }

	antlrcpp::Any visitDefvariable(GrammarParser::DefvariableContext *ctx) override{
	//TODO
	return 0;
    }
    
//EXPR
        antlrcpp::Any visitConst(GrammarParser::ConstContext *ctx) override{
        //TODO
	return 0;
    }

	antlrcpp::Any visitVar(GrammarParser::VarContext *ctx) override{
	//TODO
	return 0;
    }

	antlrcpp::Any visitPlus(GrammarParser::PlusContext *ctx) override{
	//TODO
	return 0;
    }

	antlrcpp::Any visitMinus(GrammarParser::MinusContext *ctx) override{
	//TODO
	return 0;
    }
	antlrcpp::Any visitMult(GrammarParser::MultContext *ctx) override{
	//TODO
	return 0;
    }

	antlrcpp::Any visitDiv(GrammarParser::DivContext *ctx) override{
	//TODO
	return 0;
    }

//TYPE
	antlrcpp::Any visitTypeint(GrammarParser::TypeintContext *ctx) override{
	//TODO
	return 0;
    }

//DECLVAR
	antlrcpp::Any visitDeclvar(GrammarParser::DeclvarContext *ctx) override{
	//TODO
	return 0;
    }

//OPTINIT
	antlrcpp::Any visitInitvide(GrammarParser::InitvideContext *ctx) override{
	//TODO
	return 0;
    }
	
};

