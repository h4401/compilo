
#include "Program.h"
using namespace std;


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

string Program::generateIR(){
    for(Function* func : functions){
        CFG* cfg = new CFG(func);
        func->generateIR(cfg);
        cfgs.push_back(cfg);
    }
    return "";
}
