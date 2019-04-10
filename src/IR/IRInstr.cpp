//
//  IRInstr.cpp
//  
//
//  Created by yanghua on 2019/3/29.
//
#include <iostream>

#include "IRInstr.h"
#include "CFG.h"
#include "BasicBlock.h"
using namespace std;

IRInstr::IRInstr(BasicBlock* bb_, Operation op, Type t){
    this->bb = bb_;
    this->op = op;
    this->t = t;
}

IRInstr::~IRInstr(){
    
}

std::string IRInstr::varToIndex(string name){
    return to_string(this->bb->getCfg()->get_var_index(name));
}

void AddInstr::gen_asm(ostream &o){
    o << "movl " << varToIndex(y) << "(%rbp), (%eax)" << std::endl;
    o << "addl " << varToIndex(x) << ", (%eax)" << std::endl;
    o << "movl (%eax)" << ", " << varToIndex(d) << "(%rbp)" << std::endl;
}

void SubInstr::gen_asm(ostream &o){
    o << "movl " << varToIndex(y) << "(%rbp), (%eax)" << std::endl;
    o << "subl " << varToIndex(x) << ", (%eax)" << std::endl;
    o << "movl (%eax)" << ", " << d << "(%rbp)" << std::endl;
}

void MulInstr::gen_asm(ostream &o){
    o << "movl " << varToIndex(y) << "(%rbp), (%eax)" << std::endl;
    o << "imull " << varToIndex(x) << ", (%eax)" << std::endl;
    o << "movl (%eax)" << ", " << varToIndex(d) << "(%rbp)" << std::endl;
}

void DivInstr::gen_asm(ostream &o){
    o << "movl " << varToIndex(y) << "(%rbp), (%eax)" << std::endl;
    o << "idivl " << varToIndex(x) << ", (%eax)" << std::endl;
    o << "movl (%eax)" << ", " << varToIndex(d) << "(%rbp)" << std::endl;
}

void CmpInstr::gen_asm(ostream &o){
    
}

void CallInstr::gen_asm(ostream &o){
    
}

void RmemInstr::gen_asm(ostream &o){
    
}

void WmemInstr::gen_asm(ostream &o){
    o << "movl " << varToIndex(val) << "(%rbp), (%eax)" << endl;
    o << "movl (%eax), " << varToIndex(dest) << "(%rbp)" << endl;
}

void RetInstr::gen_asm(ostream &o){
    o << "movl " << varToIndex(d) << "(%rbp), (%eax)" << endl;
}

void LdconstInstr::gen_asm(ostream &o){
    o << "movl $" << c << ", " << varToIndex(d) << "(%rbp)" << endl;    
}

void IRInstr::toString(){
    
}

void LdconstInstr::toString(){
    std::cout<<"Ldconst: "<<op<<" d:"<<d<<" "<<"c:"<<c<<" "<<std::endl;
}

void WmemInstr::toString(){
    std::cout<<"Copy: "<<op<<" d:"<<dest<<" "<<"val:"<<val<<" "<<std::endl;
}

void AddInstr::toString(){
    std::cout<<"Add: "<<op<<" d:"<<d<<" "<<"x:"<<x<<" "<<"y:"<<y<<" "<<std::endl;
}

void SubInstr::toString(){
    std::cout<<"Sub: "<<op<<" d:"<<d<<" "<<"x:"<<x<<" "<<"y:"<<y<<" "<<std::endl;
}

void MulInstr::toString(){
    std::cout<<"Mult: "<<op<<" d:"<<d<<" "<<"x:"<<x<<" "<<"y:"<<y<<" "<<std::endl;
}

void DivInstr::toString(){
    std::cout<<"Div: "<<op<<" d:"<<d<<" "<<"x:"<<x<<" "<<"y:"<<y<<" "<<std::endl;
}

void RetInstr::toString(){
    std::cout<<"Ret: "<<op<<" d:"<<d<<" "<<std::endl;
}
