#pragma once

#include "Function.h"
#include "./IR/CFG.h"
#include <vector>


class Program
{
    public:
        Program();

        virtual ~Program();
       
        void addFunction(Function * function);

        std::vector <Function*> getFunctions();

        std::string generateIR();
    private:
        std::vector <Function*> functions;
        std::vector <CFG*> cfgs;

};
