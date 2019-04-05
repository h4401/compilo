#pragma once

#include "Expression.h"
#include <fstream>

class ExprOperationBinary : public Expression {
public:
    ExprOperationBinary(Expression* expressionL, Expression* expressionR, char operateur);
    virtual ~ExprOperationBinary();
    void generateAsm(std::ofstream& o, int offset);
    char getOperateur(); 
    std::string generateIR();


private:
    Expression* expressionL;
    Expression* expressionR;
    char operateur;
};
