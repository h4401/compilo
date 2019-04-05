//
//  DeclVar.cpp
//  
//
//  Created by yanghua on 2019/3/29.
//

#include "DeclVar.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &os, const DeclVar& dv){
    os << "Variable declaration: " << dv.name << endl;
    return os;
}

