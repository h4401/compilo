//
//  ExpressionConst.cpp
//  
//
//  Created by yanghua on 2019/4/2.
//

#include "ExpressionConst.h"
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
