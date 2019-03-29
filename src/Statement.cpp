using namespace std;
#include "Statement.h"
#include <iostream>

Statement::Statement()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Statement>" << endl;
    #endif
}

Statement::~Statement()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Statement>" << endl;
    #endif
}
