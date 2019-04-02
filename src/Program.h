#pragma once

#include "Function.h"
#include "./IR/CFG.h"
#include <vector>

using namespace std;

class Program
{
    public:
        Program();

        virtual ~Program();
       
        void addFunction(Function * function);

        vector <Function*> getFunctions();

        string generateIR();    
    private:
        vector <Function*> functions;
        vector <CFG*> cfgs;
};
