#pragma once
#include "antlr4-runtime.h"
#include "GrammarBaseVisitor.h"
#include "Variable.h"
#include "Expression.h"
#include "ExprOperationBinary.h"
#include <unordered_map>
#include "Variable.h"
#include "Type.h"
#include "Program.h"
#include "Function.h"
#include "Block.h"
#include "DeclVar.h"
#include "Statement.h"
#include "Return.h"
#include "ExpressionConst.h"
#include "DefVar.h"
#include "ExprPar.h"
#include "ExecFunc.h"
#include "Param.h"
#include "If.h"
#include "Else.h"

typedef std::unordered_map<std::string, Variable*> SymbolTable;

class Visitor : public GrammarBaseVisitor {
	public:
	    Visitor();
	    virtual ~Visitor();
	    

	    //--------------------- Visiteur Programme--------------------------//
	    antlrcpp::Any visitProg(GrammarParser::ProgContext* ctx) override;

	    //--------------------- Visiteur Fonction--------------------------//
	    antlrcpp::Any visitFunc(GrammarParser::FuncContext* ctx) override;

	    //--------------------- Visiteur Block --------------------------//
	    antlrcpp::Any visitBlock(GrammarParser::BlockContext* ctx) override;

	    //--------------------- Visiteur Instruction --------------------------//
	    antlrcpp::Any visitReturn(GrammarParser::ReturnContext* ctx) override;

	    antlrcpp::Any visitDefvariable(GrammarParser::DefvariableContext* ctx) override;

	    antlrcpp::Any visitExfuncStatement(GrammarParser::ExfuncStatementContext* ctx) override;

	    antlrcpp::Any visitExprStatement(GrammarParser::ExprStatementContext* ctx) override;

	    antlrcpp::Any visitIfStatement(GrammarParser::IfStatementContext* ctx) override;
	    
	    //--------------------- Visiteur if --------------------------//
	    antlrcpp::Any visitInsif(GrammarParser::InsifContext* ctx) override;
	    
	    //--------------------- Visiteur else --------------------------//
	    antlrcpp::Any visitInselse(GrammarParser::InselseContext* ctx) override;

	    //--------------------- Visiteur Expression --------------------------//
	    antlrcpp::Any visitConst(GrammarParser::ConstContext* ctx) override;

	    antlrcpp::Any visitVar(GrammarParser::VarContext* ctx) override;

	    antlrcpp::Any visitPlus(GrammarParser::PlusContext* ctx) override;

	    antlrcpp::Any visitMinus(GrammarParser::MinusContext* ctx) override;

	    antlrcpp::Any visitMult(GrammarParser::MultContext* ctx) override;

	    antlrcpp::Any visitDiv(GrammarParser::DivContext* ctx) override;

	    antlrcpp::Any visitExfunc(GrammarParser::ExfuncContext* ctx) override;

	    antlrcpp::Any visitPar(GrammarParser::ParContext* ctx) override;
	    
	    antlrcpp::Any visitNeq(GrammarParser::NeqContext* ctx) override;
	    
	    antlrcpp::Any visitEq(GrammarParser::EqContext* ctx) override;
	    
	    antlrcpp::Any visitGt(GrammarParser::GtContext* ctx) override;
	    
	    antlrcpp::Any visitGte(GrammarParser::GteContext* ctx) override;
	    
	    antlrcpp::Any visitLte(GrammarParser::LteContext* ctx) override;
	    
	    antlrcpp::Any visitLt(GrammarParser::LtContext* ctx) override;

	    //--------------------- Visiteur Parametre fonction--------------------------//
	    antlrcpp::Any visitParamFonction(GrammarParser::ParamFonctionContext* ctx) override;

	    antlrcpp::Any visitParamVide(GrammarParser::ParamVideContext* ctx) override;

	    //--------------------- Visiteur Block --------------------------//
	    antlrcpp::Any visitTypeint(GrammarParser::TypeintContext* ctx) override;

	    //--------------------- Visiteur Declaration variable --------------------------//
	    antlrcpp::Any visitDeclvar(GrammarParser::DeclvarContext* ctx) override;

	    //--------------------- Visiteur Initialisation --------------------------//
	    antlrcpp::Any visitInitvide(GrammarParser::InitvideContext* ctx) override;
	    
	    antlrcpp::Any visitInit(GrammarParser::InitContext* ctx) override;
	    
	    void printTable();

	private:
	    std::ofstream output;

	    SymbolTable * table;

	    int offset;

	    bool error;

	    bool firstMult;
};

