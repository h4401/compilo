#include "Block.h"

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

string Block::generateIR(){
    for(DeclVar* declvar: declarations){
        declvar->generateIR();
    }
    for(Statement* statement: statements){
        statement->generateIR();
    }
    return "";
}
