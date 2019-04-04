#include "ExecFunc.h"

ExecFunc::ExecFunc(std::string name, std::vector<Expression *> expressions){
	this->name = name;
	this->expressions = expressions;
}

ExecFunc::~ExecFunc(){
}
