#include "DefVar.h"
#include "./IR/BasicBlock.h"
using namespace std;

DefVar::DefVar(Variable* variable, Expression* expression){
	this->variable = variable;
	this->expression = expression;
}

DefVar::~DefVar(){
}

ostream& operator<<(std::ostream& stream, const DefVar& definition)
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

string DefVar::generateIR(CFG* cfg){
    string right = expression->generateIR(cfg);
    string left = variable->generateIR(cfg);
    vector<string> param;
    param.push_back(left);
    param.push_back(right);

    cfg->current_bb->add_IRInstr(IRInstr::wmem,INT,param);
        return left;

}
    
