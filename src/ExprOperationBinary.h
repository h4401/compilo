#pragma once

#include "Expression.h"
#include <fstream>
#include "./IR/CFG.h"


class ExprOperationBinary : public Expression {
public:
    ExprOperationBinary(Expression* expressionL, Expression* expressionR, char operateur);
    virtual ~ExprOperationBinary();
    void generateAsm(std::ofstream& o, int offset);

    char getOperateur(); 
    std::string generateIR();
    Expression* getExpressionL();
    Expression* getExpressionR();
    std::string generateIR(CFG* cfg);



private:
    Expression* expressionL;
    Expression* expressionR;
    char operateur;
};
