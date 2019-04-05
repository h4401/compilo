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
