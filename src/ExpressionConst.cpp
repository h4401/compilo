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
    string var = cfg->create_new_tempvar(INT);
    vector<string> params;
    params.push_back(var);
    params.push_back(to_string(this->getValeur()));
    cfg->current_bb->add_IRInstr(AddInstr::ldconst,INT,params);
    return var;
    
}
