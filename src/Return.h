#pragma once
#include <iostream>
#include "Expression.h"
#include "Statement.h"

class Return : public Statement
{
    public:
	void print(std::ostream& stream) const;	

	friend std::ostream& operator<<(std::ostream& stream, const Return& retourFonction);

        Return(Expression* expression);

        virtual ~Return();
    
        std::string generateIR();
    private:
        Expression* expression;
};
