#pragma once
#include <stdio.h>
#include <iostream>

class Statement {
public:
    Statement();
//    virtual void generateAsm(std::ofstream& o, int offset);
    virtual ~Statement();
    friend std::ostream &operator<<(std::ostream &os, const Statement& s);
    virtual void print(std::ostream &os) const = 0;
    std::string generateIR();
protected:
};
