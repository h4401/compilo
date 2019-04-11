#include "ExpressionConst.h"
#include "./IR/BasicBlock.h"
using namespace std;

string ExpressionConst::generateIR(CFG* cfg){
    string var = cfg->create_new_tempvar(INT);
    vector<string> params;
    params.push_back(var);
    params.push_back(to_string(this->valeur));
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,INT,params);
    return var;   
}

ostream &operator<<(ostream &os, const ExpressionConst& eob){
    os << "Const Expression : valeur :" << eob.valeur << " ";
    return os;
}


void ExpressionConst::print(std::ostream &os) const{
    os << "Const Expression : valeur :" << valeur << " ";
}

ExpressionConst::ExpressionConst(){}

ExpressionConst::~ExpressionConst(){}
