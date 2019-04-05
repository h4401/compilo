#include "Return.h"
using namespace std;

Return::Return(Expression* expression){
	this->expression = expression;
}

Return::~Return(){

}

string Return::generateIR(){
    return "";
}
