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
    o << "\tmovl " << varToIndex(y) << "(%rbp), %eax" << std::endl;
    o << "\taddl " << varToIndex(x) << "(%rbp), %eax" << std::endl;
    o << "\tmovl %eax" << ", " << varToIndex(d) << "(%rbp)" << std::endl;
}

void SubInstr::gen_asm(ostream &o){
    o << "\tmovl " << varToIndex(y) << "(%rbp), %eax" << std::endl;
    o << "\tsubl " << varToIndex(x) << ", %eax" << std::endl;
    o << "\tmovl %eax" << ", " << d << "(%rbp)" << std::endl;
}

void MulInstr::gen_asm(ostream &o){
    o << "\tmovl " << varToIndex(y) << "(%rbp), %eax" << std::endl;
    o << "\timull " << varToIndex(x) << ", %eax" << std::endl;
    o << "\tmovl %eax" << ", " << varToIndex(d) << "(%rbp)" << std::endl;
}

void DivInstr::gen_asm(ostream &o){
    o << "\tmovl " << varToIndex(y) << "(%rbp), %eax" << std::endl;
    o << "\tidivl " << varToIndex(x) << ", %eax" << std::endl;
    o << "\tmovl %eax" << ", " << varToIndex(d) << "(%rbp)" << std::endl;
}

void CmpInstr::gen_asm(ostream &o){
    o << "\tmovl " << varToIndex(x) << "(%rbp),  %eax" << endl;
    o << "\tcmpl " <<   varToIndex(y) << "(%rbp),  %eax" << endl;

    string set = "";

    switch(op){
	case cmp_eq:
	    set = "sete";
	    break;

	case cmp_neq:
            set = "setne";
	    break;

	case cmp_lt:
            set = "setl";
	    break; 

	case cmp_lte:
            set = "setle";
	    break;

	case cmp_gt:
            set = "setg";
	    break;

	case cmp_gte:
	    set = "setge";
	    break;

	default:
	break;
    }
    o <<"\t"<< set << " %al" << endl;
    o << "\tmovzbl %al, %eax" << endl;
    o << "\tmovl %eax, " << varToIndex(d) << "(%rbp)" << std::endl;
}

void CallInstr::gen_asm(ostream &o){
    int offset;
    if(params.size()>6) cout<<"function parameters cannot be more than 6!"<<endl;
    for(int i =0;i<params.size();i++){
        offset = bb->getCfg()->get_var_index(params[i]);
        o<< "\tmovq " <<offset << "(%rbp), "<<"%" << param_register[i]<<endl;
    }
    o << "\tcallq " << label << "\n";

    if(dest != ""){
        offset = bb->getCfg()->get_var_index(dest);
        o << "\tmovl"<<" %eax, "<<offset<<"(%rbp)"<<endl;
    }
}

void RmemInstr::gen_asm(ostream &o){
    
}

void WmemInstr::gen_asm(ostream &o){
    o << "\tmovl " << varToIndex(val) << "(%rbp), %eax" << endl;
    o << "\tmovl %eax, " << varToIndex(dest) << "(%rbp)" << endl;
}

void RetInstr::gen_asm(ostream &o){
    o << "\tmovl " << varToIndex(d) << "(%rbp), %eax" << endl;
}

void LdconstInstr::gen_asm(ostream &o){
    o << "\tmovl $" << c << ", " << varToIndex(d) << "(%rbp)" << endl;    
}

void IRInstr::toString(){}

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

void CmpInstr::toString(){
     std::cout<<"Cmp: "<<op<<" "<<"x:"<<x<<" "<<"y:"<<y<<" "<<std::endl;
}
