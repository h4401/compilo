#ifndef Block_h
#define Block_h
#include <vector>
#include "Statement.h"
#include "DeclVar.h"


class Block{
public:

	Block();

	virtual ~Block();
  
  friend ostream &operator<<(ostream & os, const Block& block);
	
	std::vector<DeclVar*> getDeclarations();

	void addDeclaration(DeclVar* declaration);
   
	std::vector<Statement*> getStatements();

	void addStatement(Statement* statement);
 	
	void generateAsm(std::ofstream& o);

    std::string generateIR();
protected:
	std::vector<Statement*> statements;

	std::vector<DeclVar*> declarations;
};

#endif /* Block_h */
