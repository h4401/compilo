#include "ExecFunc.h"
#include "./IR/BasicBlock.h"
#include "./IR/CFG.h"
#include "Param.h"

using namespace std;

ExecFunc::ExecFunc(std::string name, Param* p){
	this->name = name;
	this->params = p;
}

ExecFunc::~ExecFunc(){
}

string ExecFunc::generateIR(CFG* cfg){
    
    vector<string> funcParams;
    string var = cfg->create_new_tempvar(INT);//creer et inserer la nouv var ds table symbol
    funcParams = params->generateIR(cfg); // appel de fct qui generate IRs pour chaque expr dans parametres
    vector <string> vec;
    vec.push_back(var);//dest
    vec.push_back(name);//label
    for(string s : funcParams){
        vec.push_back(s);
    }
        cfg->current_bb->add_IRInstr(IRInstr::call,INT,vec);

    return "";
}

//ostream &operator<<(ostream &os, const ExecFunc& eob){
//    os << " AppelFunction: Name=" << eob.name << " ";
//
//    for (auto it : eob.expressions)
//    {
//        os << *it;
//    }
//
//    os << endl;
//    return os;
//}


//void ExecFunc::print(std::ostream &os)
//{
//     os << " AppelFunction: Name=" << name << " ";
//
//    for (auto it : expressions)
//    {
//        os << *it;
//    }
//    
//    os << endl;
//}
