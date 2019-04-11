#include "Statement.h"

using namespace std;

ostream &operator<<(ostream &os, const Statement  &s){
    os << "Statement" <<endl;
    s.print(os);
    return os;
}

Statement::Statement()
{}

Statement::~Statement()
{}
