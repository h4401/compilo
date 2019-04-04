#include "Expression.h"
#include <string>
#include <vector>

class ExecFunc: public Expression{
public:
    ExecFunc(std::string name, std::vector<Expression *> expressions);
    virtual ~ExecFunc();
    
protected:
    std::string name;  
    std::vector<Expression *> expressions;
};
