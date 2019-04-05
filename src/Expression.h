#ifndef Expression_h
#define Expression_h

#include <stdio.h>
#include <fstream>
#include "Type.h"
#include "Statement.h"
class Expression : public Statement{
public:
    Expression();
    virtual ~Expression();
    int getOffset();
    void setOffset(int valeur);
    TypeExpr getType();
    void setType(TypeExpr type);
    int getValeur();
    void setValeur(int valeur);
    virtual void generateAsm(std::ofstream& o, int offset);
    std::ostream &operator<<(std::ostream &os);

protected:
    bool isSimple;
    int offset;
    int valeur;
    TypeExpr type;
};

#endif /* Expression_h */
