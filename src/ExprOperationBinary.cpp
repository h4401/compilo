#include "ExprOperationBinary.h"
#include "./IR/BasicBlock.h"

using namespace std;

ExprOperationBinary::ExprOperationBinary(Expression* expressionL, Expression* expressionR, string operateur)
{
    this->expressionL = expressionL;
    this->expressionR = expressionR;
    this->operateur = operateur;
}


ExprOperationBinary::~ExprOperationBinary()
{
}

string ExprOperationBinary::getOperateur()
{
    return this->operateur;
}

void ExprOperationBinary::generateAsm(ofstream& output, int offset)
{
    output << "movl " << to_string(this->expressionL->getOffset()) << "(%rbp), (%eax)" << endl;
    string val = "";
    if (this->expressionR->getType() == CONST) {
        val = "$" + to_string(this->expressionR->getValeur());
    }
    else {
        val = to_string(this->expressionR->getOffset()) + "(%rbp)";
    }
//    switch (this->operateur) {
    if(this->operateur=="+")
        output << "addl " << val << ", (%eax)" << endl;

    else if(this->operateur=="-")
        output << "subl " << val << ", (%eax)" << endl;

    else if(this->operateur=="*")
        output << "imull " << val << ", (%eax)" << endl;

    else if(this->operateur=="/")
        output << "idivl " << val << ", (%eax)" << endl;
    
    else if(this->operateur=="==")
        output << "addl " << val << ", (%eax)" << endl;

    else if(this->operateur=="!=")
        output << "subl " << val << ", (%eax)" << endl;


    else if(this->operateur=="<=")
        output << "imull " << val << ", (%eax)" << endl;


    else if(this->operateur==">=")
        output << "idivl " << val << ", (%eax)" << endl;


    
    output << "movl (%eax)"
           << ", " << to_string(offset) << "(%rbp)" << endl;
}


Expression* ExprOperationBinary::getExpressionL(){
    return expressionL;
}

Expression* ExprOperationBinary::getExpressionR(){
    return expressionR;
}

ostream &operator<<(ostream &os, const ExprOperationBinary& eob){
    os << "Binary Expression : " << endl;
    os << *eob.expressionL << *eob.expressionL << endl;
    return os;
}

void ExprOperationBinary::print(ostream &os)
{
    os << "Binary Expression : " << endl;
    os << *expressionL << *expressionL << endl;
}

string ExprOperationBinary::generateIR(CFG* cfg){
    string var = cfg->create_new_tempvar(INT);
    string var1 = expressionR->generateIR(cfg);
    string var2 = expressionL->generateIR(cfg);
    string op = this->operateur;
    vector<string> params;
    params.push_back(var);
    params.push_back(var1);
    params.push_back(var2);

    if(this->operateur=="+")
        cfg->current_bb->add_IRInstr(IRInstr::add,INT,params);
    
    else if(this->operateur=="-")
        cfg->current_bb->add_IRInstr(IRInstr::sub,INT,params);
    
    else if(this->operateur=="*")
        cfg->current_bb->add_IRInstr(IRInstr::mul,INT,params);
    
    else if(this->operateur=="/")
        cfg->current_bb->add_IRInstr(IRInstr::div,INT,params);
    
    else if(this->operateur=="==")
        cfg->current_bb->add_IRInstr(IRInstr::cmp_eq,INT,params);
    
    else if(this->operateur=="!=")
        cfg->current_bb->add_IRInstr(IRInstr::cmp_neq,INT,params);
    
    else if(this->operateur==">=")
        cfg->current_bb->add_IRInstr(IRInstr::cmp_gte,INT,params);
    
    else if(this->operateur=="<=")
        cfg->current_bb->add_IRInstr(IRInstr::cmp_lte,INT,params);
    
    
    
    
    return var;
}
