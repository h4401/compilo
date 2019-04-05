//
//  IRInstr.h
//  
//
//  Created by yanghua on 2019/3/29.
//

#ifndef IRInstr_h
#define IRInstr_h

#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>

#include "../Type.h"
class BasicBlock;
class CFG;
class DefFonction;

class IRInstr {
    
public:
    /** The instructions themselves -- feel free to subclass instead */
    typedef enum {
        ldconst,
        add,
        sub,
        mul,
        div,
        rmem,
        wmem,
        call,
        cmp_eq,
        cmp_lt,
        cmp_le
    } Operation;
    
    
    /**  constructor */
    IRInstr(BasicBlock* bb_, Operation op, Type t);
    ~IRInstr();
    /** Actual code generation */
    void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
    
private:
    BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
    Operation op;
    Type t;
    
};
#endif /* IRInstr_h */

class LdconstInstr : public IRInstr {
public:
    LdconstInstr(BasicBlock* bb_, Type t, std::string destination, std::string constant) : IRInstr(bb_, ldconst, t), d(destination), c(constant) {}
//    virtual void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
private:
    std::string d;
    std::string c;
};

class AddInstr : public IRInstr {
public:
    AddInstr(BasicBlock* bb_, Type t, std::string destination, std::string operand1, std::string operand2) : IRInstr(bb_, add, t), d(destination), x(operand1), y(operand2) {}
    /** Actual code generation */
//    virtual void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
    private :
    std::string d;
    std::string x;
    std::string y;
};

class SubInstr : public IRInstr {
public:
    SubInstr(BasicBlock* bb_, Type t, std::string destination, std::string operand1, std::string operand2) : IRInstr(bb_, add, t), d(destination), x(operand1), y(operand2) {}
    /** Actual code generation */
//    virtual void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
    private :
    std::string d;
    std::string x;
    std::string y;
};

class MulInstr : public IRInstr {
public:
    MulInstr(BasicBlock* bb_, Type t, std::string destination, std::string operand1, std::string operand2) : IRInstr(bb_, add, t), d(destination), x(operand1), y(operand2) {}
    /** Actual code generation */
//    virtual void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
    private :
    std::string d;
    std::string x;
    std::string y;
};

class DivInstr : public IRInstr {
public:
    DivInstr(BasicBlock* bb_, Type t, std::string destination, std::string operand1, std::string operand2) : IRInstr(bb_, add, t), d(destination), x(operand1), y(operand2) {}
    /** Actual code generation */
//    virtual void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
    private :
    std::string d;
    std::string x;
    std::string y;
};

class CmpInstr : public IRInstr {
public:
    CmpInstr(BasicBlock* bb_, Operation op, Type t, std::string operand1, std::string operand2) : IRInstr(bb_, op, t), x(operand1), y(operand2) {}
    /** Actual code generation */
//    virtual void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
    private :
    std::string x;
    std::string y;
};

class CallInstr : public IRInstr {
public:
    CallInstr(BasicBlock* bb_, Type t, std::vector<std::string>& oneParams) : IRInstr(bb_, call, t){
        dest = oneParams.at(0);
        label = oneParams.at(1);
        size_t length = oneParams.size();
        for(size_t i = 2; i < length; i++){
            params.push_back(oneParams.at(i));
        }
    }
    /** Actual code generation */
//    virtual void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
    private :
    std::string dest;
    std::string label; //?
    std::vector<std::string> params;
};

class RmemInstr : public IRInstr {
public:
    RmemInstr(BasicBlock* bb_, Type t, std::string destination, std::string address) : IRInstr(bb_, rmem, t), dest(destination), addr(address) {}
    /** Actual code generation */
//    virtual void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
    private :
    std::string dest;
    std::string addr;
};

class WmemInstr : public IRInstr {
public:
    WmemInstr(BasicBlock* bb_, Type t, std::string destination, std::string valeur) : IRInstr(bb_, wmem, t), dest(destination), val(valeur) {}
    /** Actual code generation */
//    virtual void gen_asm(std::ostream &o); /**< x86 assembly code generation for this IR instruction */
    private :
    std::string dest;
    std::string val;
};
