#pragma once

#include "Expression.h"

class Return : public Statement
{
    public:
        Return(Expression* expression);

        virtual ~Return();
    
        std::string generateIR();
    private:
        Expression* expression;
};
