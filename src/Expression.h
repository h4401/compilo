#ifndef Expression_h
#define Expression_h

#include <stdio.h>
#include <fstream>
#include "Statement.h"
//#include "./IR/CFG.h"
class CFG;

enum TypeExpr {
    CONST = 0,
    VAR = 1,
    EXPRBINAIRE = 2
};

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
    virtual std::string generateIR(CFG* cfg);


protected:
    bool isSimple;
    int offset;
    int valeur;
    TypeExpr type;
};



#endif /* Expression_h */
