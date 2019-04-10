//
//  Param.h
//  
//
//  Created by yanghua on 2019/4/9.
//

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
  
private:
    std::vector<Expression*> vecExpr;
};
