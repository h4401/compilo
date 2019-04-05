#include "Variable.h"
#include <iostream>
using namespace std;
Variable::Variable(std::string name, int memOffset, bool initialized)
{
    this->name = name;
    this->memOffset = memOffset;
    this->initialized = initialized;
};

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
    os << "Variable" << endl;
    os << "Value: " << v.valeur << "," << v.memOffset << endl;
    return os;
}   
 
void Variable::setType(Type t){
    this->type = t;
}

Type Variable::getType(){
    return this->type;
}
