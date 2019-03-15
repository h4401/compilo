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
    
        antlrcpp::Any visitRet(GrammarParser::RetContext *ctx) override{
        return (int) visit(ctx->expr());
    }
    
        antlrcpp::Any visitConst(GrammarParser::ConstContext *ctx) override{
        return (int) stoi(ctx->INT()->getText());
    }
    

    
};

