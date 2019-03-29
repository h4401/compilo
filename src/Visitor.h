#pragma once
#include "antlr4-runtime.h"
#include "GrammarBaseVisitor.h"
#include "Variable.h"
#include "Expression.h"
#include "ExprOperationBinary.h"
#include <unordered_map>

class Visitor : public GrammarBaseVisitor {
public:
    Visitor();
    virtual ~Visitor();

    // PROG
    antlrcpp::Any visitProg(GrammarParser::ProgContext* ctx) override;

    // FUNC
    antlrcpp::Any visitFunc(GrammarParser::FuncContext* ctx) override;

    //BLOCK
    antlrcpp::Any visitBlock(GrammarParser::BlockContext* ctx) override;

    // STATEMENT
    antlrcpp::Any visitReturn(GrammarParser::ReturnContext* ctx) override;

    antlrcpp::Any visitDefvariable(GrammarParser::DefvariableContext* ctx) override;

    //EXPR
    antlrcpp::Any visitConst(GrammarParser::ConstContext* ctx) override;

    antlrcpp::Any visitVar(GrammarParser::VarContext* ctx) override;

    antlrcpp::Any visitPlus(GrammarParser::PlusContext* ctx) override;

    antlrcpp::Any visitMinus(GrammarParser::MinusContext* ctx) override;

    antlrcpp::Any visitMult(GrammarParser::MultContext* ctx) override;

    antlrcpp::Any visitDiv(GrammarParser::DivContext* ctx) override;

    antlrcpp::Any visitExfunc(GrammarParser::ExfuncContext* ctx) override;

    antlrcpp::Any visitPar(GrammarParser::ParContext* ctx) override;

    //TYPE
    antlrcpp::Any visitTypeint(GrammarParser::TypeintContext* ctx) override;

    //DECLVAR
    antlrcpp::Any visitDeclvar(GrammarParser::DeclvarContext* ctx) override;

    //OPTINIT
    antlrcpp::Any visitInitvide(GrammarParser::InitvideContext* ctx) override;

private:
    std::ofstream output;
    std::unordered_map<std::string, Variable*> table;
    int offset;
    bool error;
    bool firstMult;
};

