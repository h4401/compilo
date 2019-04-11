//
//  CFG.cpp
//  
//
//  Created by yanghua on 2019/3/29.
//
#include <iostream>
#include "CFG.h"
#include "BasicBlock.h"
using namespace std;

CFG::CFG(Function* ast){
    this->ast = ast;
    nextFreeSymbolIndex = 0;
    for(pair<string,Variable*> element : *(ast->getSymbolTable())){
        SymbolType.insert(pair<string,Type>(element.first,element.second->getType()));
        SymbolIndex.insert(pair<string,int>(element.first,element.second->getOffset()));
        nextFreeSymbolIndex = (ast->getSymbolTable()->size()-ast->getParameters().size())*(-4);
        
    }
    BasicBlock* bb = new BasicBlock(this,"PROLOGUE");
    bbs.push_back(bb);
    BasicBlock* bbFunct = new BasicBlock(this, ast->getName());
    bb->set_exit_true(bbFunct);
    current_bb = bbFunct;
    if (nextFreeSymbolIndex !=0){
        current_bb -> setLastVar((--SymbolIndex.end())->first);
    }
    bbs.push_back(bbFunct);
    BasicBlock* bbExit = new BasicBlock(this,"EPILOGUE");
    bbs.push_back(bbExit);
    current_bb->set_exit_true(bbExit);
    bbExit->set_exit_true(nullptr);
    nextBBnumber = 0;
    //todo
}

CFG::~CFG(){
}

void CFG::createBB(){
    BasicBlock* bb = new BasicBlock(this, to_string(nextBBnumber++));
    bbs.push_back(bb);
}

void CFG::addBB(BasicBlock * bb){
    bbs.push_back(bb);
}
int CFG::next_BB_number(){
    return ++nextBBnumber;
}

void CFG::add_to_symbol_table(string name,Type t){
    SymbolType.insert(make_pair(name,t));
    SymbolIndex.insert(make_pair(name,nextFreeSymbolIndex));
    
}

string CFG::create_new_tempvar(Type t){
    string name;
    nextFreeSymbolIndex -= 4;
    name = "!tmp" + to_string(nextFreeSymbolIndex);
    add_to_symbol_table(name,t);
    current_bb -> setLastVar(name);
    return name;
}

void CFG::gen_asm(ostream &o){
    gen_asm_prologue(o);
    for(int i=0; i<bbs.size(); i++){
	if(i!=0 && i!=2){
	bbs[i]->printInstrs();
        bbs[i]->gen_asm(o);
        }
    }
    gen_asm_epilogue(o);
}

void CFG::gen_asm_prologue(ostream& o){
        o << ".file \"test.c\"" << endl;
        o << ".text" << endl;
        o << ".global main" << endl;
        o << ".type main, @function" << endl;
        o << "main:" << endl;
        o << "\tpushq  %rbp" << endl;
        o << "\tmovq %rsp, %rbp" << endl;
        o << "\tsubq $"<< to_string(nextFreeSymbolIndex+4)<<", %rsp"<<endl;
        for(int i = 0 ; i < ast->getParameters().size(); i++){
            int offset = get_var_index(ast->getParameters()[i]->getName());
            o<< "\tmovq %" << param_register[i]<<", "<<to_string(offset)<<"%(rbp)"<<endl;
        }
        o << "   " << endl;

}

void CFG::gen_asm_epilogue(ostream& o){
    //a verifier
        o << endl << "."<< ast->getName() <<"_BB_EPILOGUE:" << endl;
        o << "\tpopq %rbp" << endl;
        o << "\tret" << endl;
        o << "   " << endl;

}


int CFG::get_var_index(string name){
    auto it = SymbolIndex.find(name);
    if(it != SymbolIndex.end()){
        return (it->second);
    }else{
        return 999;
    }
}
