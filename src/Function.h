#pragma once

#include <unordered_map>
#include <string>
#include "Block.h"
#include "Type.h"
//#include "Variable.h"

class CFG;
class Variable;
typedef std::unordered_map<std::string, Variable*> SymbolTable;


using namespace std;


class Function
{
    public:
	Function(SymbolTable* table, string name, Block * block, Type returnType,vector<DeclVar*> vecDecl);

        virtual ~Function();
        
	friend ostream & operator<<(ostream & stream, const Function & function);

	std::vector<DeclVar*> getParameters();

	void setParameters(vector <DeclVar*> parameters);
    

        string getName();

        Block * getBlock();

        Type getReturnType ();
    
        string generateIR(CFG* cfg);
    
        SymbolTable* getSymbolTable();


	//virtual void generateAssembly(ofstream& f, unordered_map<string, Variable*>& addressTable);

    private:
	SymbolTable* table;
        std::string name;
        Block* block;
        std::vector<DeclVar*> parameters;
        Type returnType;
};
