#pragma once

#include "Block.h"
#include "./IR/CFG.h"

class Else
{
    public:
        std::string generateIR(CFG * cfg);

        void print(std::ostream& stream) const;

        friend std::ostream& operator<< (std::ostream& stream, const Else& anElse);

        Else(Block* block);

        virtual ~Else();

    private:
        Block* block;
};
