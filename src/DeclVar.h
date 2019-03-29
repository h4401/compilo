//
//  DeclVar.h
//  
//
//  Created by yanghua on 2019/3/29.
//

#ifndef DeclVar_h
#define DeclVar_h
#include <string>
class DeclVar
{
public:
    
    void generateAsm(std::ostream& stream);
    void setName();
    std::string getName();
  
protected:
    std::string name;
    
};

#endif /* DeclVar_h */
