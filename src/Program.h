#pragma once

#include "Function.h"

#include <vector>

using namespace std;

class Program
{
    public:
        Program();

        virtual ~Program();
       
        void addFunction(Function * function);

        vector <Function*> getFunctions();

    private:
        vector <Function*> functions;
};
