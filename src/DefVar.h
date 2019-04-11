#pragma once

#include <iostream>
#include "Variable.h"
#include "Expression.h"
#include "Statement.h"
#include "./IR/CFG.h"

class DefVar : public Statement
{
    public:
        DefVar(Variable* variable, Expression* expression);

        virtual ~DefVar();
	
	friend std::ostream& operator<< (std::ostream& stream, const DefVar& definition);
	
	void print(std::ostream& stream) const;
    
    	std::string generateIR(CFG* cfg);

    private:
        Variable* variable;

        Expression* expression;
};
