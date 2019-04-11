#include "Statement.h"

using namespace std;

ostream &operator<<(ostream &os, const Statement  &s){
    s.print(os);
    return os;
}

Statement::Statement()
{}

Statement::~Statement()
{}
