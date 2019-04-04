//
//  ExpressionConst.h
//  
//
//  Created by yanghua on 2019/4/2.
//

#ifndef ExpressionConst_h
#define ExpressionConst_h
#include "Expression.h"

class CFG;

class ExpressionConst: public Expression{
public:
    ExpressionConst();
    virtual ~ExpressionConst();
    std::string generateIR(CFG* cfg);
protected:
    
};
#endif /* ExpressionConst_h */
