#ifndef Expression_h
#define Expression_h

#include <stdio.h>
#include "Type.h"
class Expression {
public:
    Expression();
    virtual ~Expression();
    int getOffset();
    void setOffset(int valeur);
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
