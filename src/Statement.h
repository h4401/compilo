#pragma once
#include <stdio.h>
#include <iostream>

class Statement {
public:
    Statement();
//    virtual void generateAsm(std::ofstream& o, int offset);
    virtual ~Statement();
    std::string generateIR();
protected:
};
