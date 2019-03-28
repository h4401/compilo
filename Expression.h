//
//  Expression.h
//  
//
//  Created by yanghua on 2019/3/27.
//

#ifndef Expression_h
#define Expression_h

#include <stdio.h>
#include "Type.h"
class Expression{
public:
    Expression();
    virtual ~Expression();
    void setOffset(int valeur);
    int getOffset();
    TypeExpr getType();
    void setType(TypeExpr type);
    int getValeur();
    void setValeur(int valeur);
    
protected:
    bool isSimple;
    int offset;
    int valeur;
    TypeExpr type;
};

#endif /* Expression_h */
