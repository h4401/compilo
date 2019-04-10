#include "ExecFunc.h"
using namespace std;

ExecFunc::ExecFunc(std::string name, std::vector<Expression *> expressions){
	this->name = name;
	this->expressions = expressions;
}

ExecFunc::~ExecFunc(){
}

string ExecFunc::generateIR(CFG* cfg){
    return "";
}

ostream &operator<<(ostream &os, const ExecFunc& eob){
    os << " AppelFunction: Name=" << eob.name << " ";

    for (auto it : eob.expressions)
    {
        os << *it;
    }
    
    os << endl;
    return os;
}


void ExecFunc::print(std::ostream &os)
{
     os << " AppelFunction: Name=" << name << " ";

    for (auto it : expressions)
    {
        os << *it;
    }
    
    os << endl;
}
