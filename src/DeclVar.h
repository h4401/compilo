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

class DeclVar
{
public:
    DeclVar();
    ~DeclVar();
    void generateAsm(std::ostream& o);
    void setName();
    std::string getName();
    std::string generateIR();
  
protected:
    std::string name;
    
};

#endif /* DeclVar_h */
