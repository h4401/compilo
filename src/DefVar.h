#pragma once

#include "Variable.h"
#include "Expression.h"

class DefVar : public Statement
{
    public:
        DefVar(Variable* variable, Expression* expression);

        virtual ~DefVar();

    private:
        Variable* variable;

        Expression* expression;
};
