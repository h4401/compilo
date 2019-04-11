#include <iostream>
#include "antlr4-runtime.h"
#include "src/GrammarLexer.h"
#include "src/GrammarParser.h"
#include "src/GrammarBaseVisitor.h"
#include "src/Visitor.h"
#include "src/Program.h"

using namespace antlr4;
using namespace std;

int main(int argc, char* argv[])
{

    /*** Arguments check ***/
    if (argc < 2) {
        cout << "Missing argument : Path to input file" << endl;
        return -1;
    }

    const char* fileName = argv[1];

    /*** Creating file ***/
    ifstream file;
    file.open(fileName);

    if (!file) {
        cout << "Error : Problem occured while oppening the file" << endl;
        return -1;
    }

    /*** Parsing the tree and Generating Assebly ***/

    cout << "Generating Abstract Syntaxic Tree" << endl;
    ANTLRInputStream input(file);
    GrammarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    GrammarParser parser(&tokens);
    tree::ParseTree* tree = parser.prog();
    Visitor visitor;
    Program* prog = visitor.visit(tree);
    cout << "Abstract Syntaxic Tree generated" << endl;
    

    /*************  IR ********************/
    cout << "Generating IR" << endl;
    prog->generateIR();
    cout << "IR Generated" << endl<<endl;

    /********** DEBUG *************/
    //visitor.printTable();       //test for symboltable
    //cout << "AST :" << endl << *prog <<endl ;
    
   /******* Generating Assembly ********/ 
    cout << "Generating Assembly" << endl;
    ofstream o;
    o.open("asm.s");
    o << ".file \"asm.c\"" << endl;
    o << ".globl main" << endl;
    prog->gen_asm(o);
    o.close();
    cout << "Assembly generated to ./asm.s" << endl;

    return 1;
}
