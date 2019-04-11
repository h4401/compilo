#include "ExprPar.h"
using namespace std;

string ExprPar::generateIR(CFG* cfg){
    string var = expr->generateIR(cfg);
    return var; 
}

ostream &operator<<(ostream &os, const ExprPar& expression){
    os << "Parantheses : " << expression << " ";
    return os;
}


void ExprPar::print(std::ostream &os) const{
    os << "Parantheses : " << *expr << " ";
}

ExprPar::ExprPar(Expression * expr){
    this->expr = expr;
}

ExprPar::~ExprPar(){}

