#include "Statement.h"
#include <iostream>
using namespace std;

Statement::Statement()
{

}

Statement::~Statement()
{

}
string Statement::generateIR(){
    return "";
}

ostream &operator<<(ostream &os, const Statement  &s){
    os << "Statement" <<endl;
    return os;
}