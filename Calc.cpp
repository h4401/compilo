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

using namespace std;

	Calc::Calc(){
	offset = 0;
  	output.open("asm.s");
	error = false;
	}

	Calc::~Calc(){
	output.close();
	}

// PROG
        antlrcpp::Any Calc::visitProg(GrammarParser::ProgContext *ctx) {
		
	return (int)visit(ctx->func(0));    
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
	return (int)visit(ctx->block());
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
			return (int)visit(ret);
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
	int returnVal = (int)visit(ctx->ret()->expr());
        output << "mov eax, "<<  to_string(returnVal) << endl;
  	output << "popq %rbp" << endl;
	output << "ret" << endl;
	return returnVal;
    }

//DefVar
	    antlrcpp::Any Calc::visitDefvariable(GrammarParser::DefvariableContext *ctx) {
	string name = ctx -> defvar()-> ID()-> getText();
	std::unordered_map<std::string,Variable *>::const_iterator it = table.find(name);
	if (it == table.end()){
		int line = ctx -> getStart() -> getLine();
	   	 cerr << "[-] Error (Line " << to_string(line) << "): Undefined variable " << name << endl;
	   	error = true;
		return -1;
	}
	else
	{
		int value = visit(ctx -> defvar()-> expr());
	   	it->second->setInitialized();
        it->second->setValeur(to_string(value));
		output << "movl $" << to_string(value) << ", "<<to_string(it->second->getOffset())<< "(%rbp)" << endl;
		return value;
	}
	
    }
    
//EXPR
        antlrcpp::Any Calc::visitConst(GrammarParser::ConstContext *ctx) {
	return (int) stoi(ctx->INT()->getText());
    }

	antlrcpp::Any Calc::visitVar(GrammarParser::VarContext *ctx) {
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
		return (int)stoi(it-> second -> getValeur());
    }

	antlrcpp::Any Calc::visitPlus(GrammarParser::PlusContext *ctx) {
	//TODO
	return 0;
    }

	antlrcpp::Any Calc::visitMinus(GrammarParser::MinusContext *ctx) {
	//TODO
	return 0;
    }
	antlrcpp::Any Calc::visitMult(GrammarParser::MultContext *ctx) {
	//TODO
	return 0;
    }

	antlrcpp::Any Calc::visitDiv(GrammarParser::DivContext *ctx) {
	//TODO
	return 0;
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
                
                offset -=8;
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


