#include "DeclVar.h"
#include <iostream>
#include <string>
using namespace std;

ostream &operator<<(ostream &os, const DeclVar& dv){
    os << "Variable declarations: " << dv.type << " " ;
    for(auto it: dv.names)
    {
	os<< it << " ";
    }
    os << endl;
    return os;
}

void DeclVar::print(ostream &os) const{
    os << "Variable declarations: " << this->type << " " ;
    for(auto it: this->names)
    {
	os<< it << " ";
    }
    os << endl;
}

void DeclVar::addName(string name){
	this->names.push_back(name);
}

string DeclVar::generateIR(CFG* cfg){
    return "";
}

vector<string> DeclVar::getNames(){
    return this->names;
}


DeclVar::DeclVar(Type type){
    this->type = type;
}

DeclVar::~DeclVar(){}
