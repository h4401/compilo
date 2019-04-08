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
    nextFreeSymbolIndex = 0;
    for(pair<string,Variable*> element : *(ast->getSymbolTable())){
        SymbolType.insert(pair<string,Type>(element.first,element.second->getType()));
        SymbolIndex.insert(pair<string,int>(element.first,element.second->getOffset()));
        nextFreeSymbolIndex += 4;
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
//    nextBBnumber = 1;
    //todo
}

CFG::~CFG(){
}

void CFG::add_to_symbol_table(string name,Type t){
    SymbolType.insert(make_pair(name,t));
    nextFreeSymbolIndex += 4;
    SymbolIndex.insert(make_pair(name,nextFreeSymbolIndex));
}

string CFG::create_new_tempvar(Type t){
    string name;
    name = "!tmp" + to_string(nextFreeSymbolIndex);
    add_to_symbol_table(name,t);
    return name;
}

void CFG::gen_asm(ostream &o){
    current_bb->printInstrs();
    for(auto bb : bbs){
        if(bb->getLabel()==".PROLOGUE"+ast->getName()){
            gen_asm_prologue(o);
        }else if(bb->getLabel()==".EPILOGUE"+ast->getName()){
            gen_asm_epilogue(o);
        }else{
            bb->gen_asm(o);
        }
    }
}

void CFG::gen_asm_prologue(ostream& o){
    //a corriger
        o << ".file \"test.c\"" << endl;
        o << ".text" << endl;
        o << ".global main" << endl;
        o << ".type main, @function" << endl;
        o << "main:" << endl;
        o << "pushq  %rbp" << endl;
        o << "movq %rsp, %rbp" << endl;
        o << "   " << endl;

}

void CFG::gen_asm_epilogue(ostream& o){
    //a verifier
        o << "popq %rbp" << endl;
        o << "ret" << endl;
        o << "   " << endl;

}

int CFG::get_var_index(string name){
    auto it = SymbolIndex.find(name);
    if(it != SymbolIndex.end()){
        return (-1*it->second);
    }else{
        return -99;
    }
}
