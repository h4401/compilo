//
//  Param.cpp
//  
//
//  Created by yanghua on 2019/4/9.
//

#include "Param.h"
using namespace std;

Param::Param(vector<Expression*> vecExpr){
    this->vecExpr = vecExpr;
}

vector<string> Param::generateIR(CFG* cfg){
    vector<string> params;
    for(Expression* e : vecExpr){
        string var = e->generateIR(cfg);
        params.push_back(var);
    }
    return params;

}

Param::~Param(){
    
}
