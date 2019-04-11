#pragma once
#include <vector>
#include "Expression.h"

using namespace std;

class Param
{
	public:
	    Param(vector<Expression*> vecExpr);

	    ~Param();

	    std::vector<string> generateIR(CFG* cfg);
	  
            void print(ostream &os);

	    friend ostream &operator<<(ostream &os, const Param& param);
	private:
	    std::vector<Expression*> vecExpr;
};
