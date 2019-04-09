//
//  IRInstr.cpp
//  
//
//  Created by yanghua on 2019/3/29.
//
#include <iostream>

#include "IRInstr.h"
using namespace std;

IRInstr::IRInstr(BasicBlock* bb_, Operation op, Type t){
    this->bb = bb_;
    this->op = op;
    this->t = t;
}

IRInstr::~IRInstr(){
    
}


void AddInstr::gen_asm(ostream &o){
    
}

void SubInstr::gen_asm(ostream &o){
    
}

void MulInstr::gen_asm(ostream &o){
}

void DivInstr::gen_asm(ostream &o){
    
}

void CmpInstr::gen_asm(ostream &o){
    
}

void CallInstr::gen_asm(ostream &o){
    
}

void RmemInstr::gen_asm(ostream &o){
    
}

void WmemInstr::gen_asm(ostream &o){
    
}

void RetInstr::gen_asm(ostream &o){
    
}

void LdconstInstr::gen_asm(ostream &o){
    o << "movl $" << this->c << ", " << this->d << "(%rbp)" << endl;    
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
