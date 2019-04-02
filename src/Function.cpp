#include "Function.h"

Function::Function(string name, Block * block, Type returnType){
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



