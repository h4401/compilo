//
//  Expression.cpp
//  
//
//  Created by yanghua on 2019/3/27.
//

#include "Expression.h"
using namespace std;

Expression::Expression(){
};

Expression::~Expression(){
    
};

void Expression::setOffset(int valeur){
    this->offset = valeur;
}

int Expression::getOffset(){
    return this->offset;
}

int Expression::getValeur(){
    return this->valeur;
}

void Expression::setValeur(int valeur){
    this->valeur = valeur;
}

TypeExpr Expression::getType(){
    return this->type;
}

void Expression::setType(TypeExpr type){
    this->type = type;
}


