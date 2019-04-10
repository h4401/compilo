#include "ExpressionConst.h"
#include "./IR/BasicBlock.h"
using namespace std;

ExpressionConst::ExpressionConst(){
    
}

ExpressionConst::~ExpressionConst(){
    
}

string ExpressionConst::generateIR(CFG* cfg){
    //a changer
    string var = cfg->create_new_tempvar(INT);//creer et inserer la nouv var ds table symbol
    vector<string> params;
    params.push_back(var);
    params.push_back(to_string(this->valeur));
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,INT,params);
    return var;
    
}

ostream &operator<<(ostream &os, const ExpressionConst& eob){
    os << "Binary Expression : " << endl;
    os << "valeur :" << eob.valeur << endl;
    return os;
}


void ExpressionConst::print(std::ostream &os){
    os << "Binary Expression : " << endl;
    os << "valeur :" << valeur << endl;
}
