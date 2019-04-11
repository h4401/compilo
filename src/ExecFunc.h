#pragma once
#include "Expression.h"
#include <string>
#include <vector>

class CFG;
class Param;
class ExecFunc: public Expression{
	public:
	    ExecFunc(std::string name, Param* p);

	    virtual ~ExecFunc();

	    std::string generateIR(CFG* cfg);

	    friend std::ostream &operator<<(std::ostream &os,const ExecFunc& eob);

	    void print(std::ostream &os) const;
	    
	protected:
	    std::string name;  

	    Param* params;
};
