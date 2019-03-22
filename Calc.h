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
        antlrcpp::Any visitProg(GrammarParser::ProgContext *ctx) override{
        return (int) visit(ctx->func(0));
    }
    
    
        antlrcpp::Any visitFunc(GrammarParser::FuncContext *ctx) override{
        return (int) visit(ctx->deffunc());
    }
    
        antlrcpp::Any visitDeffunc(GrammarParser::DeffuncContext *ctx) override{
        return (int) visit(ctx->block());
    }
    
        antlrcpp::Any visitBlock(GrammarParser::BlockContext *ctx) override{
        return (int) visit(ctx->statement(0));
    }
    
        antlrcpp::Any visitStatement(GrammarParser::StatementContext *ctx) override{
        return (int) visit(ctx->ret());
    }
    
        antlrcpp::Any visitReturn(GrammarParser::RetContext *ctx) override{
        return (int) visit(ctx->expr());
    }
    
        antlrcpp::Any visitConst(GrammarParser::ConstContext *ctx) override{
        return (int) stoi(ctx->INT()->getText());
    }
	antlrcpp::Any visitVar(GrammarParser::ProgContext *ctx) override{
	//TODO
	return 0;
    }
	antlrcpp::Any visitPlus(GrammarParser::ProgContext *ctx) override{
	//TODO
	return 0;
    }
	antlrcpp::Any visitMinus(GrammarParser::ProgContext *ctx) override{
	//TODO
	return 0;
    }
	antlrcpp::Any visitMult(GrammarParser::ProgContext *ctx) override{
	//TODO
	return 0;
    }
	antlrcpp::Any visitDiv(GrammarParser::ProgContext *ctx) override{
	//TODO
	return 0;
    }
	antlrcpp::Any visitDefvariable(GrammarParser::ProgContext *ctx) override{
	//TODO
	return 0;
    }
	antlrcpp::Any visitTypeint(GrammarParser::ProgContext *ctx) override{
	//TODO
	return 0;
    }
	antlrcpp::Any visitDeclvar(GrammarParser::ProgContext *ctx) override{
	//TODO
	return 0;
    }
	antlrcpp::Any visitInitvide(GrammarParser::ProgContext *ctx) override{
	//TODO
	return 0;
    }
	
    

    
};

