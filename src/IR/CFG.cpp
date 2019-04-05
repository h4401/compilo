//
//  CFG.cpp
//  
//
//  Created by yanghua on 2019/3/29.
//
#include <iostream>
#include "CFG.h"
using namespace std;

CFG::CFG(Function* ast){
    this->ast = ast;
    for(pair<string,Variable*> element : *(ast->getSymbolTable())){
        SymbolType.insert(pair<string,Type>(element.first,element.second->getType()));
        SymbolIndex.insert(pair<string,int>(element.first,element.second->getOffset()));
    }
    BasicBlock* bb = new BasicBlock(this,".PROLOGUE"+ast->getName());
    bbs.push_back(bb);
    BasicBlock* bbFunct = new BasicBlock(this, ast->getName());
    bb->set_exit_true(bbFunct);
    current_bb = bbFunct;
    bbs.push_back(bbFunct);
    BasicBlock* bbExit = new BasicBlock(this,".EPILOGUE"+ast->getName());
    bbs.push_back(bbExit);
    current_bb->set_exit_true(bbExit);
    bbExit->set_exit_true(nullptr);
    nextFreeSymbolIndex = 0;
//    nextBBnumber = 1;
    //todo
}

CFG::~CFG(){
}


string CFG::create_new_tempvar(Type t){
    string name;
    name = "!tmp" + to_string(nextFreeSymbolIndex+4);
    return name;
}

void CFG::gen_asm(ostream &o){
//    for(auto bb : bbs){

        bbs[1]->gen_asm(o);
//    }
}
