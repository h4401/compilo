#include "Function.h"

Function::Function(SymbolTable* table, string name, Block * block, Type returnType){
	this->table = table;	
	this->name = name;
	this->block = block;
	this->returnType = returnType;
}

Function::~Function(){
}

std::vector<DeclVar*> Function::getParameters()
{
    return this->parameters;
}

void Function::setParameters(std::vector<DeclVar*> parameters)
{
    this->parameters = parameters;
}

string Function::getName()
{
    return this->name;
}

Block * Function::getBlock()
{
    return this->block;
}


Type Function::getReturnType ()
{
    return this->returnType;
}

string Function::generateIR(CFG* cfg){
    
    this->block->generateIR();
    return "";
}

SymbolTable* Function::getSymbolTable(){
    return this->table;
}


