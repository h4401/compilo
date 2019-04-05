#pragma once
#include <string>
class Variable {

public:
    Variable(std::string name, int offset, bool initialized);
    int getOffset();
    bool isInitialized();
    void setInitialized();
    std::string getValeur();
    void setValeur(std::string val);
    friend std::ostream &operator<<(std::ostream &os, const Variable& v);

private:
    std::string name;
    int memOffset;
    bool initialized;
    std::string valeur;
};
