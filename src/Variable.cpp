#include "Variable.h"
#include <iostream>
using namespace std;

int Variable::getOffset()
{
    return memOffset;
};

bool Variable::isInitialized()
{
    return initialized;
}

void Variable::setInitialized()
{
    initialized = true;
}

string Variable::getValeur()
{
    return valeur;
}

void Variable::setValeur(string val)
{
    this->valeur = val;
}

ostream &operator<<(ostream &os, const Variable& v){
    os << "Variable: " << "name: " << v.name <<" offset: "<<to_string(v.memOffset)<<" valeur: "<<v.valeur<<" Type: "<<to_string(v.type) << " ";
    return os;
}   
 
void Variable::print(ostream &os){
    os << "Variable: " << "name: " << name <<" offset: "<<to_string(memOffset)<<" valeur: "<<valeur<<" Type: "<< to_string(type)<< " ";
}

void Variable::setType(Type t){
    this->type = t;
}

Type Variable::getType(){
    return this->type;
}

string Variable::generateIR(CFG* cfg){
    return this->name;
}

Variable::Variable(std::string name, int memOffset, bool initialized)
{
    this->name = name;
    this->memOffset = memOffset;
    this->initialized = initialized;
};

Variable::~Variable(){}
