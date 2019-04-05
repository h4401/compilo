//
//  CFG.cpp
//  
//
//  Created by yanghua on 2019/3/29.
//

#include "CFG.h"
using namespace std;

CFG::CFG(Function* ast){
    this->ast = ast;
    for(pair<string,Variable*> element : *(ast->getSymbolTable())){
        SymbolType.insert(pair<string,Type>(element.first,element.second->getType()));
        SymbolIndex.insert(pair<string,int>(element.first,element.second->getOffset()));
    }
}

CFG::~CFG(){
}

