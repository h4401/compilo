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
    s.print(os);
    return os;
}
