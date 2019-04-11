#include "Program.h"
using namespace std;

ostream & operator<<(ostream & stream, const Program & programme)
{
    stream << "Programme:" << endl;

    for (auto function :  programme.functions)
    {
        stream << *function << endl;
    }

    stream << endl;

    return stream;
}


void Program::addFunction(Function *function)
{
    this->functions.push_back(function);
}


vector <Function*> Program::getFunctions()
{
    return this->functions;
}


string Program::generateIR(){
    for(Function* func : functions){
        CFG* cfg = new CFG(func);
        func->generateIR(cfg);
        cfgs.push_back(cfg);
    }
    return "";
}


void Program::gen_asm(ostream & o){
    for(CFG* cfg : cfgs){
        cfg->gen_asm(o);
    }
}


Program::Program(){}


Program::~Program(){}


