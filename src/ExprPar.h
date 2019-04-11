#pragma once
#include "Expression.h"

class ExprPar: public Expression{
	public:
	    ExprPar(Expression* expr);
	
	    virtual ~ExprPar();

	    std::string generateIR(CFG* cfg);

	    void print(std::ostream &os);

	protected:
	    Expression* expr;    
};

