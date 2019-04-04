//
//  DeclVar.h
//  
//
//  Created by yanghua on 2019/3/29.
//

#ifndef DeclVar_h
#define DeclVar_h
#include <string>
#include <iostream>
#include "Type.h"

class DeclVar
{
public:
    DeclVar(std::string name, Type type);
    virtual ~DeclVar();

    void generateAsm(std::ostream& o);
    void setName();
    std::string getName();
    std::string generateIR();
  
protected:
    Type type;
    std::string name;
    
};

#endif /* DeclVar_h */
