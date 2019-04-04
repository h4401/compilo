#include "ExprPar.h"
using namespace std;
ExprPar::ExprPar(Expression * expr){
    this->expr = expr;
}

ExprPar::~ExprPar(){
    
}

string ExprPar::generateIR(){
    return "";
}
