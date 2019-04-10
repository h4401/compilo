using namespace std;

#include "Else.h"
#include <iostream>
#include <string>



string Else::generateIR(CFG * cfg)
{
    cout << "Else::generateIR" << endl;
    block->generateIR(cfg);
    return "";
}


void Else::print(std::ostream &stream) const
{
    stream << "     Else: " << endl << *block << endl;
}

std::ostream& operator<<(std::ostream& stream, const Else& anElse)
{
    stream << "     Else: " << endl <<  *anElse.block << endl;
}

Else::Else(Block* block)
{
    this->block = block;
}

Else::~Else()
{
}
