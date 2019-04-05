#include "DefVar.h"
using namespace std;
DefVar::DefVar(Variable* variable, Expression* expression){
	this->variable = variable;
	this->expression = expression;
}

DefVar::~DefVar(){
}

std::ostream& operator<<(std::ostream& stream, const DefVar& definition)
{
    stream << " Affectation: " << *definition.variable << " Operateur: =";
    stream << " " << *definition.expression<< endl;
    return stream;
}

void DefVar::print(std::ostream& stream) const
{
    stream << " Affectation: " << *(variable) << " Operateur: =";
    stream << " " << *(expression)<< endl;
}
