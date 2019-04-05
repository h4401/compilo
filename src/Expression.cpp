#include "Expression.h"
using namespace std;

Expression::Expression(){}

Expression::~Expression(){}

int Expression::getOffset()
{
    return this->offset;
}

void Expression::setOffset(int valeur)
{
    this->offset = valeur;
}

int Expression::getValeur()
{
    return this->valeur;
}

void Expression::setValeur(int valeur)
{
    this->valeur = valeur;
}

TypeExpr Expression::getType()
{
    return this->type;
}

void Expression::setType(TypeExpr type)
{
    this->type = type;
}

void Expression::generateAsm(std::ofstream& o, int offset){}

std::ostream &operator<<(std::ostream &os, Expression e){
    os << "Expression: " << e.getValeur() << "," << e.getType() << "," << e.getOffset() << endl;
    return os;
} 