//
//  Block.cpp
//  
//
//  Created by yanghua on 2019/3/29.
//

#include "Block.h"
#include <iostream>
using namespace std;

Block::Block(){
    
}

Block::~Block(){
    
}

void Block::addStatement(Statement* stat){
    statements.push_back(stat);
}

void Block::generateAsm(ofstream& o){
//    for(int i = 0;i<statements.size();i++){
//        statements[i]->generateAsm(o,);
//    }
//    for(int i = 0;i<declVars.size();i++){
//        declVars[i]->generateAsm(o);
//    }
}

std::vector<Statement*> Block::getStatements(){
    return statements;
}

std::vector<DeclVar*> Block::getDeclVars(){
    return declVars;
}

ostream & operator<<(ostream & os, const Block &block){
    for(Statement* st : block.statements){
        os << st << endl;
    }
    for (DeclVar* dv : block.declVars){
        os << dv << endl;
    }
    return os;
}