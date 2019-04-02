//
//  Type.cpp
//  
//
//  Created by yanghua on 2019/3/30.
//

#include "Type.h"

Type::Type(std::string name){
    this->typeName = name;
}

Type::~Type(){
    
}

std::string Type::getTypeName(){
    return this->typeName;
    
}
