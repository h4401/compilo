#pragma once

#include "Expression.h"
#include <fstream>
#include "./IR/CFG.h"


class ExprOperationBinary : public Expression {
public:
    ExprOperationBinary(Expression* expressionL, Expression* expressionR, char operateur);
    virtual ~ExprOperationBinary();
    void generateAsm(std::ofstream& o, int offset);
    friend std::ostream &operator<<(std::ostream &os,const ExprOperationBinary& eob);
    void print(std::ostream &os);

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
