using namespace std;

#include "Program.h"

void Program::addFunction(Function *function)
{
    this->functions.push_back(function);
}

vector <Function*> Program::getFunctions()
{
    return this->functions;
}

Program::Program()
{
}

Program::~Program()
{
}
