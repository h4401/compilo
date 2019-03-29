//
//  Block.h
//  
//
//  Created by yanghua on 2019/3/29.
//

#ifndef Block_h
#define Block_h
#include <vector>
#include "Statement.h"
#include <iostream>
#include "DeclVar.h"

class Block{
public:
    Block();
    virtual ~Block();
    void addStatement(Statement* stat);
    void generateAsm(std::ofstream& o);
protected:
    std::vector<Statement*>statements;
    std::vector<DeclVar*>declVars;
};

#endif /* Block_h */
