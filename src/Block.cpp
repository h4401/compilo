#include "Block.h"
#include <iostream>

using namespace std;

std::vector<Statement*> Block::getStatements()
{
    return this->statements;
}

void Block::addStatement(Statement* statement){
    statements.push_back(statement);
}

//std::vector<DeclVar*> Block::getDeclarations()
//{
  //  return this->declarations;
//}

//void Block::addDeclaration(DeclVar* declaration){
  //  declarations.push_back(declaration);
//}


ostream & operator<<(ostream & os, const Block &block){
    //for (DeclVar* dv : block.declarations){
      //  os << *dv << endl;
    //}
    for(Statement* st : block.statements){
        os << *st << endl;
    }
    return os;
}

string Block::generateIR(CFG* cfg){
    //for(DeclVar* declvar: declarations){
      //  declvar->generateIR(cfg);
    //}
    for(Statement* statement: statements){
        statement->generateIR(cfg);
    }
    return "";
}


Block::Block(){}

Block::~Block(){}

