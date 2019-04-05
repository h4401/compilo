#include "DeclVar.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &os, const DeclVar& dv){
    os << "Variable declaration: " << dv.name << endl;
    return os;
}

DeclVar::DeclVar(string name, Type type){
    this->name = name;
    this->type = type;
}
DeclVar::~DeclVar(){

}

string DeclVar::generateIR(){
    return "";
}
