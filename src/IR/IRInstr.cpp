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


void LdconstInstr::gen_asm(ostream &o){
    o << "movl $" << this->c << ", " << this->d << "(%rbp)" << endl;    
}
