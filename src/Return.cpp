#include "Return.h"
#include "./IR/BasicBlock.h"
using namespace std;

string Return::generateIR(CFG* cfg){
    string var = this->expression->generateIR(cfg);
    vector<string> params;
    params.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ret,INT,params);
    return var;
}

void Return::print(std::ostream& stream) const{
    stream << " RetourFonction: " << *expression << endl;
}

std::ostream& operator<<(std::ostream& stream, const Return& retourFonction)
{
    stream << " RetourFonction: " << *retourFonction.expression << endl;
    return stream;
}

Return::Return(Expression* expression){
	this->expression = expression;
}

Return::~Return(){}
