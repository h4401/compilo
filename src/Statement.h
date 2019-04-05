#include <stdio.h>
#include <iostream>

class Statement {
public:
    Statement();
//    virtual void generateAsm(std::ofstream& o, int offset);
    virtual ~Statement();
    friend std::ostream &operator<<(std::ostream &os, const Statement& s);

protected:
};

