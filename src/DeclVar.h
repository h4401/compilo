#pragma once
//
//  DeclVar.h
//  
//
//  Created by yanghua on 2019/3/29.
//
#include <string>
#include <iostream>
#include "Type.h"

class CFG;
class DeclVar
{
public:
    DeclVar(std::string name, Type type);
    virtual ~DeclVar();

    void generateAsm(std::ostream& o);
    void setName();
    friend std::ostream &operator<<(std::ostream &os, const DeclVar& dv);
    void print(std::ostream &os);
    std::string getName();
    std::string generateIR(CFG* cfg);
  

protected:
    Type type;
    std::string name;
};

