#pragma once
#include <stdio.h>
#include <iostream>

class CFG;
class Statement {
	public:
	    Statement();
	    virtual ~Statement();
	    friend std::ostream &operator<<(std::ostream &os, const Statement& s);
	    virtual void print(std::ostream &os) const = 0;
	    virtual std::string generateIR(CFG* cfg)=0;
	protected:
    
};
