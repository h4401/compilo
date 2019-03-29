//
//  Block.cpp
//  
//
//  Created by yanghua on 2019/3/29.
//

#include "Block.h"
using namespace std;

Block::Block(){
    
}

Block::~Block(){
    
}

void Block::addStatement(Statement* stat){
    statements.push_back(stat);
}

void Block::generateAsm(ofstream& o){
    for(int i = 0;i<statements.size();i++){
        statements[i].generateAsm(o);
    }
    for(int i = 0;i<declVars.size();i++){
        declVars[i].generateAsm(o);
    }
}
