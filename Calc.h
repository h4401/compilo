//
//  Calc.h
//  
//
//  Created by yanghua on 2019/3/10.
//

#pragma once
#include "antlr4-runtime.h"
#include "MainBaseVisitor.h"

using namespace std;

class Calc: public MainBaseVisitor {
public:
        antlrcpp::Any visitProg(MainParser::ProgContext *ctx) override{
        return (int) visit(ctx->func(0));
    }
    
    
        antlrcpp::Any visitFunc(MainParser::FuncContext *ctx) override{
        return (int) visit(ctx->deffunc());
    }
    
        antlrcpp::Any visitDeffunc(MainParser::DeffuncContext *ctx) override{
        return (int) visit(ctx->block());
    }
    
        antlrcpp::Any visitBlock(MainParser::BlockContext *ctx) override{
        return (int) visit(ctx->statement(0));
    }
    
        antlrcpp::Any visitStatement(MainParser::StatementContext *ctx) override{
        return (int) visit(ctx->ret());
    }
    
        antlrcpp::Any visitRet(MainParser::RetContext *ctx) override{
        return (int) visit(ctx->expr());
    }
    
        antlrcpp::Any visitConst(MainParser::ConstContext *ctx) override{
        return (int) stoi(ctx->INT()->getText());
    }
    

    
};

