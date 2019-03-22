#include "Variable.h"
Variable::Variable(std::string name, int memOffset, bool initialized)
{
   	this->name = name;
    	this->memOffset = memOffset;
	this->initialized = initialized;
};

int Variable::getOffset(){
    	return memOffset;
};

bool Variable::isInitialized(){
    	return initialized;
}

void Variable::setInitialized(){
    	initialized = true;
}
