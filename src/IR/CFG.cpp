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
    BasicBlock* bb = new BasicBlock(this,".PROLOGUE"+ast->getName());
    current_bb = bb;
    BasicBlock* bbExit = new BasicBlock(this,".EPILOGUE"+ast->getName());
    bbs.push_back(bbExit);
    current_bb->set_exit_true(bbExit);
    bbExit->set_exit_true(nullptr);
    nextFreeSymbolIndex = 0;
    nextBBnumber = 1;
    //todo
}

CFG::~CFG(){
}


string CFG::create_new_tempvar(Type t){
    string name;
    name = "!tmp" + to_string(nextFreeSymbolIndex+4);
    return name;
}

