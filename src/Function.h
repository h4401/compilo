#pragma once

#include <string>
#include "Block.h"
#include "Type.h"
#include "./IR/CFG.h"

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
    
        string generateIR(CFG* cfg);

	//virtual void generateAssembly(ofstream& f, unordered_map<string, Variable*>& addressTable);

    private:
        std::string name;
        Block* block;
        std::vector<DeclVar*> parameters;
        Type returnType;
};
