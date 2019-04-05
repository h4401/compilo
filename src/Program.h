#pragma once

#include "Function.h"
#include "./IR/CFG.h"
#include <vector>
#include <iostream>


class Program
{
    public:
        Program();

        virtual ~Program();

	friend ostream & operator<<(ostream & stream, const Program & Program);
       
        void addFunction(Function * function);

        std::vector <Function*> getFunctions();

        std::string generateIR();
    
        void gen_asm(ostream & o);
    private:
        std::vector <Function*> functions;
        std::vector <CFG*> cfgs;

};
