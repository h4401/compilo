#pragma once

#include "Expression.h"
#include <fstream>
#include <string>
#include "./IR/CFG.h"


class ExprOperationBinary : public Expression {
	public:
	    ExprOperationBinary(Expression* expressionL, Expression* expressionR, string operateur);

	    virtual ~ExprOperationBinary();

	    friend std::ostream &operator<<(std::ostream &os,const ExprOperationBinary& eob);

	    void print(std::ostream &os);

	    std::string getOperateur(); 

	    std::string generateIR();

	    Expression* getExpressionL();

	    Expression* getExpressionR();

	    std::string generateIR(CFG* cfg);

	private:
	    Expression* expressionL;

	    Expression* expressionR;

	    string operateur;
};
