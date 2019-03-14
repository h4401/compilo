//
//  Main.cpp
//  
//
//  Created by yanghua on 2019/3/10.
//

#include <iostream>
#include "antlr4-runtime.h"
#include "MainLexer.h"
#include "MainParser.h"
#include "MainBaseVisitor.h"
#include "Calc.h"

using namespace antlr4;
using namespace std;

int main(int,const char **){
    ifstream is ("2.c");
    
    if (!is)
    {
        cout << "erreur ouverture fichier" << endl;
        return -1;
    }
    
    ANTLRInputStream input(is);
    MainLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
       MainParser parser(&tokens);
       tree::ParseTree* tree = parser.prog();
                           
    
                           
       Calc visitor;
       int result = (int)visitor.visit(tree);
       cout<<"Result"<<result<<endl;
       return 0;
}
