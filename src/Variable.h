#pragma once
#include <string>
#include "Type.h"
class Variable {

public:
    Variable(std::string name, int offset, bool initialized);
    int getOffset();
    bool isInitialized();
    void setInitialized();
    std::string getValeur();
    void setValeur(std::string val);
    Type getType();
    void setType(Type t);

private:
    std::string name;
    int memOffset;
    bool initialized;
    std::string valeur;
    Type type;
};
