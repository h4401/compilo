#pragma once
#include <string>
#include "Type.h"
#include "Expression.h"
class Variable : public Expression{

public:
    Variable(std::string name, int offset, bool initialized);
    int getOffset();
    bool isInitialized();
    void setInitialized();
    std::string getValeur();
    void setValeur(std::string val);
    friend std::ostream &operator<<(std::ostream &os, const Variable& v);
    Type getType();
    void setType(Type t);
    std::string generateIR(CFG* cfg);

private:
    std::string name;
    int memOffset;
    bool initialized;
    std::string valeur;
    Type type;
};
