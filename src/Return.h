#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Expression.h"
#include "Statement.h"
#include "./IR/CFG.h"

class Return : public Statement
{
    public:
	void print(std::ostream& stream) const;	

	friend std::ostream& operator<<(std::ostream& stream, const Return& retourFonction);

        Return(Expression* expression);

        virtual ~Return();
    
        std::string generateIR(CFG* cfg);
    private:
        Expression* expression;
};
