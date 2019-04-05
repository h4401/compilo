#pragma once
#include "Expression.h"
#include <string>
#include <vector>

class ExecFunc: public Expression{
public:
    ExecFunc(std::string name, std::vector<Expression *> expressions);
    virtual ~ExecFunc();
    std::string generateIR(CFG* cfg);
    
protected:
    std::string name;  
    std::vector<Expression *> expressions;
};
