#ifndef ExprPar_h
#define ExprPar_h
#include "Expression.h"

class ExprPar: public Expression{
public:
    ExprPar(Expression* expr);
    virtual ~ExprPar();
    
protected:
    Expression* expr;    
};
#endif /* ExprPar_h */
