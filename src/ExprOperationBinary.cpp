#include "ExprOperationBinary.h"
#include "./IR/BasicBlock.h"

using namespace std;

ExprOperationBinary::ExprOperationBinary(Expression* expressionL, Expression* expressionR, char operateur)
{
    this->expressionL = expressionL;
    this->expressionR = expressionR;
    this->operateur = operateur;
}


ExprOperationBinary::~ExprOperationBinary()
{
}

char ExprOperationBinary::getOperateur()
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
    switch (this->operateur) {
    case '+':
        output << "addl " << val << ", (%eax)" << endl;
        break;

    case '-':
        output << "subl " << val << ", (%eax)" << endl;
        break;

    case '*':
        output << "imull " << val << ", (%eax)" << endl;
        break;

    case '/':
        output << "idivl " << val << ", (%eax)" << endl;
        break;

    default:
        break;
    }
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
    char op = this->operateur;
    vector<string> params;
    params.push_back(var);
    params.push_back(var1);
    params.push_back(var2);

    switch (op) {
        case '+':
            cfg->current_bb->add_IRInstr(IRInstr::add,INT,params);
            break;
        case '-':
            cfg->current_bb->add_IRInstr(IRInstr::sub,INT,params);
            break;
        case '*':
            cfg->current_bb->add_IRInstr(IRInstr::mul,INT,params);
            break;
        case '/':
            cfg->current_bb->add_IRInstr(IRInstr::div,INT,params);
            break;

            
        default:
            break;
    }
    return var;
}
