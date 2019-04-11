#pragma once
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "Statement.h"
class CFG;

enum TypeExpr {
    CONST = 0,
    VAR = 1,
    EXPRBINAIRE = 2
};

class Expression : public Statement {
	public:
	    Expression();

	    virtual ~Expression();

	    int getOffset();

	    void setOffset(int valeur);

	    TypeExpr getType();

	    void setType(TypeExpr type);

	    int getValeur();

	    void setValeur(int valeur);

	    friend std::ostream &operator<<(std::ostream &os, const Expression& e);

	    virtual void print(std::ostream& stream) const ;

	    virtual std::string generateIR(CFG* cfg)=0;
	    
	protected:
	    int offset;

	    int valeur;

	    TypeExpr type;
};



