#include "DeclVar.h"
using namespace std;

DeclVar::DeclVar(string name, Type type){
    this->name = name;
    this->type = type;
}
DeclVar::~DeclVar(){

}

string DeclVar::generateIR(){
    return "";
}
