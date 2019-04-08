#include "ExprOperationBinary.h"

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

void ExprOperationBinary::generateAsm(std::ofstream& output, int offset)
{
    output << "movl " << std::to_string(this->expressionL->getOffset()) << "(%rbp), (%eax)" << std::endl;
    std::string val = "";
    if (this->expressionR->getType() == CONST) {
        val = "$" + std::to_string(this->expressionR->getValeur());
    }
    else {
        val = std::to_string(this->expressionR->getOffset()) + "(%rbp)";
    }
    switch (this->operateur) {
    case '+':
        output << "addl " << val << ", (%eax)" << std::endl;
        break;

    case '-':
        output << "subl " << val << ", (%eax)" << std::endl;
        break;

    case '*':
        output << "imull " << val << ", (%eax)" << std::endl;
        break;

    case '/':
        output << "idivl " << val << ", (%eax)" << std::endl;
        break;

    default:
        break;
    }
    output << "movl (%eax)"
           << ", " << std::to_string(offset) << "(%rbp)" << std::endl;
}


Expression* ExprOperationBinary::getExpressionL(){
    return expressionL;
}

Expression* ExprOperationBinary::getExpressionR(){
    return expressionR;
}

std::ostream &operator<<(std::ostream &os, ExprOperationBinary eob){
    os << "Binary Expression : " << std::endl;
    os << eob.getExpressionL() << eob.getExpressionR() << std::endl;
    return os;
}

std::string ExprOperationBinary::generateIR(CFG* cfg){
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
