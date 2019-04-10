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
            instrs.push_back(new LdconstInstr(this,t,params[0], params[1]));
            break;
	case IRInstr::wmem:
            instrs.push_back(new WmemInstr(this,t,params[0], params[1]));
            break;
        case IRInstr::add:
            instrs.push_back(new AddInstr(this, t, params[0], params[1], params[2]));
            break;
        case IRInstr::sub:
            instrs.push_back(new SubInstr(this, t, params[0], params[1], params[2]));
            break;
        case IRInstr::mul:
            instrs.push_back(new MulInstr(this, t, params[0], params[1], params[2]));
            break;
        case IRInstr::div:
            instrs.push_back(new DivInstr(this, t, params[0], params[1], params[2]));
            break;
 	case IRInstr::ret:
            instrs.push_back(new RetInstr(this, t, params[0]));
            break;
    }
}

void BasicBlock::gen_asm(ostream& o){
    cout<<"instrs size: "<<instrs.size()<<endl;
    for(auto irinstr : instrs){
        irinstr->gen_asm(o);
    }
}

string BasicBlock::getLabel(){
    return this->label;
}

void BasicBlock::printInstrs(){
    for(int i = 0;i<instrs.size();i++){
        instrs[i]->toString();
    }
}

CFG* BasicBlock::getCfg(){
	return this->cfg;
}
