#pragma once

#include "Expression.h"
#include <fstream>

class ExprOperationBinary : public Expression {
public:
    ExprOperationBinary(Expression* expressionL, Expression* expressionR, char operateur);
    virtual ~ExprOperationBinary();
    void generateAsm(std::ofstream& o, int offset);
    char getOperateur();
    Expression* getExpressionL();
    Expression* getExpressionR();

private:
    Expression* expressionL;
    Expression* expressionR;
    char operateur;
};
