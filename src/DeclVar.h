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
    
    void generateAsm(std::ostream& o);
    void setName();
    friend std::ostream &operator<<(std::ostream &os, const DeclVar& dv);
protected:
    std::string name;
};

#endif /* DeclVar_h */
