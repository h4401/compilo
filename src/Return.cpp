#include "Return.h"
#include "./IR/BasicBlock.h"
using namespace std;

Return::Return(Expression* expression){
	this->expression = expression;
}

Return::~Return(){

}

string Return::generateIR(CFG* cfg){
    string var = this->expression->generateIR(cfg);
    vector<string> params;
    params.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ret,INT,params);
    return var;
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
