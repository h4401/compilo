#include "Expression.h"
#include "Type.h"

using namespace std;

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

std::ostream &operator<<(std::ostream &os, const Expression& e){
    e.print(os);
    return os;
} 

void Expression::print(std::ostream& stream) const{

}

Expression::Expression(){}

Expression::~Expression(){}
