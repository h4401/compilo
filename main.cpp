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
    cout << "Generating Assembly" << endl;

    ANTLRInputStream input(file);
    GrammarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    GrammarParser parser(&tokens);
    tree::ParseTree* tree = parser.prog();
    Visitor visitor;
    Program* prog = visitor.visit(tree);
    //visitor.printTable();       //test for symboltable
    //cout << *prog <<endl ;
    prog->generateIR();
    
    ofstream o;
    o.open("asm.s");
    prog->gen_asm(o);
    o.close();
    //cout<<*prog<<endl;
    cout << "Abstract Syntaxic Tree generated" << endl;
    cout << "Assembly generated to ./asm.s" << endl;

    return 1;
}
