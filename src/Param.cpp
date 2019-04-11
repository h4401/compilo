#include "Param.h"
using namespace std;

vector<string> Param::generateIR(CFG* cfg){
    vector<string> params;
    for(Expression* e : vecExpr){
        string var = e->generateIR(cfg);
        params.push_back(var);
    }
    return params;

}

ostream &operator<<(ostream &os, const Param& param){
    for (auto it : param.vecExpr)
    {
	os << *it << " ";
    }
    return os;
}

void Param::print(ostream &os){
    for (auto it : vecExpr)
    {
	os << *it << " ";
    }
}


Param::Param(vector<Expression*> vecExpr){
    this->vecExpr = vecExpr;
}

Param::~Param(){
    
}
