#include "DefVar.h"

DefVar::DefVar(Variable* variable, Expression* expression){
	this->variable = variable;
	this->expression = expression;
}

DefVar::~DefVar(){
}
