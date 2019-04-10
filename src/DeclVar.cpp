#include "DeclVar.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &os, const DeclVar& dv){
    os << "Variable declaration: " << dv.type << " " << dv.name << endl;
    return os;
}

void DeclVar::print(ostream &os){
    os << "Variable declaration: " << this->type << " " << this->name << endl;
}

DeclVar::DeclVar(string name, Type type){
    this->name = name;
    this->type = type;
}

DeclVar::~DeclVar(){

}

string DeclVar::generateIR(CFG* cfg){
    return "";
}
