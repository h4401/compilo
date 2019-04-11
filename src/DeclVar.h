#pragma once
//
//  DeclVar.h
//  
//
//  Created by yanghua on 2019/3/29.
//
#include <string>
#include <iostream>
#include <vector>
#include "Type.h"
#include "Statement.h"

class CFG;
class DeclVar : public Statement
{
	public:
	    DeclVar(Type type);
	    
	    virtual ~DeclVar();

 	    void generateAsm(std::ostream& o);

	    void addName(std::string name);

	    friend std::ostream &operator<<(std::ostream &os, const DeclVar& dv);

	    void print(std::ostream &os) const;

	    std::vector<std::string> getNames();

	    std::string generateIR(CFG* cfg);
	  

	protected:
	    Type type;

	    std::vector<std::string> names;
};

