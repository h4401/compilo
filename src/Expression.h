#pragma once
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "Statement.h"
//#include "./IR/CFG.h"
class CFG;

enum TypeExpr {
    CONST = 0,
    VAR = 1,
    EXPRBINAIRE = 2
};

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
    virtual void generateAsm(std::ofstream& o, int offset);

    friend std::ostream &operator<<(std::ostream &os, const Expression& e);
    //virtual void print(std::ostream& stream) const ;
    virtual std::string generateIR(CFG* cfg)=0;
    
protected:
    bool isSimple;
    int offset;
    int valeur;
    TypeExpr type;
};



