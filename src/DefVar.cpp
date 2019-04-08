#include "DefVar.h"
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
    int offset = cfg->get_var_index(right);
    vector<string> param;
    string var = cfg->create_new_tempvar(INT);
    int val;
    if(expression->getType()==0)
        val = expression->getValeur();
    param.push_back(var);
    param.push_back(to_string(val));

    cfg->current_bb->add_IRInstr(IRInstr::wmem,INT,param);
        return left;

}
    
