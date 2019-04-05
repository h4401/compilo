#include "Block.h"
#include <iostream>

using namespace std;

Block::Block(){

}

Block::~Block(){

}

std::vector<Statement*> Block::getStatements()
{
    return this->statements;
}

void Block::addStatement(Statement* statement){
    statements.push_back(statement);
}

std::vector<DeclVar*> Block::getDeclarations()
{
    return this->declarations;
}

void Block::addDeclaration(DeclVar* declaration){
    declarations.push_back(declaration);
}

void Block::generateAsm(ofstream& o){
//    for(int i = 0;i<statements.size();i++){
//        statements[i]->generateAsm(o,);
//    }
//    for(int i = 0;i<declVars.size();i++){
//        declVars[i]->generateAsm(o);
//    }
}


ostream & operator<<(ostream & os, const Block &block){
    for(Statement* st : block.statements){
        os << *st << endl;
    }
    for (DeclVar* dv : block.declarations){
        os << *dv << endl;
    }
    return os;
}

string Block::generateIR(CFG* cfg){
    for(DeclVar* declvar: declarations){
        declvar->generateIR(cfg);
    }
    for(Statement* statement: statements){
        statement->generateIR(cfg);
    }
    return "";
}

