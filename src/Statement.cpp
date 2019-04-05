#include "Statement.h"

using namespace std;

Statement::Statement()
{

}

Statement::~Statement()
{

}


ostream &operator<<(ostream &os, const Statement  &s){
    os << "Statement" <<endl;
    return os;
}
