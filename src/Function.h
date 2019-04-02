#pragma once

#include <string>
#include "Block.h"
#include "Type.h"

using namespace std;

class Function
{
    public:
	Function(string name, Block * block, Type returnType);

        virtual ~Function();
        
	std::vector<DeclVar*> getParameters();

	void setParameters(vector <DeclVar*> parameters);

        string getName();

        Block * getBlock();

        Type getReturnType ();
    

	//virtual void generateAssembly(ofstream& f, unordered_map<string, Variable*>& addressTable);

    private:
        std::string name;
        Block* block;
        std::vector<DeclVar*> parameters;
        Type returnType;
};
