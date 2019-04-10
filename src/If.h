#pragma once

#include "Statement.h"
#include "Block.h"
#include "Else.h"
#include "Expression.h"
#include "./IR/CFG.h"

class If : public Statement
{

    public:
        void print(std::ostream& stream) const;

        std::string generateIR(CFG * cfg);

        friend std::ostream& operator<< (std::ostream& stream, const If& anIf);

        void setElse(Else* anElse);

        If(Expression* condition, Block* bloc);

        virtual ~If();

    private:
        Expression* condition;

        Block* block;

        Else* anElse;

        bool hasElse = false;
};
