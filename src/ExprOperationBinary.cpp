#include "ExprOperationBinary.h"
#include "./IR/BasicBlock.h"

using namespace std;

string ExprOperationBinary::getOperateur()
{
    return this->operateur;
}

Expression* ExprOperationBinary::getExpressionL(){
    return expressionL;
}

Expression* ExprOperationBinary::getExpressionR(){
    return expressionR;
}

ostream &operator<<(ostream &os, const ExprOperationBinary& eob){
    os << "Binary Expression : " << *eob.expressionL << " "<< eob.operateur << "" << *eob.expressionL << " ";
    return os;
}

void ExprOperationBinary::print(ostream &os) const
{
    os << "Binary Expression : "<< *expressionL << " "<< operateur << "" << *expressionL << " ";
}

string ExprOperationBinary::generateIR(CFG* cfg){
    string var1 = expressionR->generateIR(cfg);
    string var2 = expressionL->generateIR(cfg);
    string var = cfg->create_new_tempvar(INT);
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

    else if(this->operateur==">")
        cfg->current_bb->add_IRInstr(IRInstr::cmp_gt,INT,params);
    
    else if(this->operateur=="<")
        cfg->current_bb->add_IRInstr(IRInstr::cmp_lt,INT,params);

    return var;
}

ExprOperationBinary::ExprOperationBinary(Expression* expressionL, Expression* expressionR, string operateur)
{
    this->expressionL = expressionL;
    this->expressionR = expressionR;
    this->operateur = operateur;
}

ExprOperationBinary::~ExprOperationBinary(){}

