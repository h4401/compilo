//
//  BasicBlock.cpp
//  
//
//  Created by yanghua on 2019/3/29.
//

#include "BasicBlock.h"
using namespace std;

BasicBlock::BasicBlock(CFG* cfg,string entry_lable){
    this->cfg = cfg;
    this->label = entry_lable;
}

void BasicBlock::set_exit_true(BasicBlock* bb){
    exit_true = bb;
}

void BasicBlock::set_exit_false(BasicBlock* bb){
    exit_false = bb;
}

BasicBlock* BasicBlock::get_exit_false(){
    return this->exit_false;
}

BasicBlock* BasicBlock::get_exit_true(){
    return this->exit_true;
}

void BasicBlock::add_IRInstr(IRInstr::Operation op,Type t,vector<string>params){
    switch(op){
        case IRInstr::ldconst:
            string destination = params[0];
            string constant = params[1];
            instrs.push_back(new LdconstInstr(this,t,destination, constant));
    }
}
