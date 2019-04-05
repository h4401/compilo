#include "Return.h"
using namespace std;

class CFG;
Return::Return(Expression* expression){
	this->expression = expression;
}

Return::~Return(){

}

string Return::generateIR(CFG* cfg){
    this->expression->generateIR(cfg);
    return "";
}

void Return::print(std::ostream& stream) const{
    stream << " RetourFonction: " << *expression;
    stream << endl;

}

std::ostream& operator<<(std::ostream& stream, const Return& retourFonction)
{
    stream << " RetourFonction: " << *retourFonction.expression;
    stream << endl;
    return stream;
}
