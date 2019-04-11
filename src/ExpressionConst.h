#pragma once
//
//  ExpressionConst.h
//  
//
//  Created by yanghua on 2019/4/2.
//
#include "Expression.h"
#include "./IR/CFG.h"
class ExpressionConst: public Expression{
	public:
	    ExpressionConst();

	    virtual ~ExpressionConst();

	    std::string generateIR(CFG* cfg);

	    friend std::ostream &operator<<(std::ostream &os,const ExpressionConst& expr);

	    void print(std::ostream &os) const;

	protected:
    
};
