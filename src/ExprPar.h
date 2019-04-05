#pragma once
#include "Expression.h"

class ExprPar: public Expression{
public:
    ExprPar(Expression* expr);
    virtual ~ExprPar();
    std::string generateIR();
protected:
    Expression* expr;    
};

