#include "Function.h"

Function::Function(SymbolTable* table, string name, Block * block, Type returnType){
	this->table = table;	
	this->name = name;
	this->block = block;
	this->returnType = returnType;
}

Function::~Function(){
}

ostream & operator<<(ostream & stream, const Function & function)
{
    stream << " Fonction: Name=" << function.name << " TypeRetour=" << function.returnType << endl;

    if(function.parameters.size()!= 0)
    {
        stream << "     Param:" << endl;

        for (auto it : function.parameters)
        {
            stream << *it;
        }
    }

    stream << *function.block;

    return stream;
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


