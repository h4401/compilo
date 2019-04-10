using namespace std;

#include "If.h"
#include <iostream>
#include <string>
#include "./IR/BasicBlock.h"


string If::generateIR(CFG * cfg)
{
    cout << "If::generateIR" << endl;
    string conditionRes = condition->generateIR(cfg);

    BasicBlock* afterBB = new BasicBlock(cfg, to_string(cfg -> next_BB_number()));
    BasicBlock* thenBB = new BasicBlock(cfg, to_string(cfg -> next_BB_number()));
    
    BasicBlock* elseBB;
    if (hasElse){
    	elseBB = new BasicBlock(cfg, to_string(cfg -> next_BB_number()));
    }
    string blockRes = block->generateIR(cfg);
    
    afterBB -> set_exit_true( cfg-> current_bb -> get_exit_true());
    afterBB -> set_exit_false ( cfg-> current_bb -> get_exit_false());
    
    cfg -> current_bb -> set_exit_true(thenBB);
    if (hasElse){
        cfg -> current_bb -> set_exit_false(elseBB);
    }else{
    	cfg -> current_bb -> set_exit_false(afterBB);
    }
    thenBB -> set_exit_true(afterBB);
 
    elseBB -> set_exit_true(afterBB);
    
    cfg -> current_bb = afterBB;

    cfg -> addBB(afterBB);
    cfg -> addBB(thenBB);
    if (hasElse){
        cfg -> addBB(elseBB);
	string elseRes = anElse->generateIR(cfg);
    }
	
    
	/*
    // Add instructions of condition
    


    trueBB -> set_exit_true(continueBB);


    // Ad-d jump (jump if condition is false) to the next label (either else or afterif)
    // ex : .L2
    cfg->current_bb->addIRInstr(IRInstr(COMPJUMP,{to_string(labelNextBlock),result.substr(4)}));
    // Add instructions of the then part
    block->generateIR(cfg);

    // If there is an else, generate basic block for else
    if(this->hasElse)
    {
        // Else is the next block
        labelNextBlock++; // Increase label
        // Instruction to jump from the then part to afterif
        // ex : .L3
        controlFlowGraph->addIRInstr(IRInstr(RETIF,{to_string(labelNextBlock)}));
        anElse->generateIR(controlFlowGraph, labelNextBlock-1);
    }

    // After if
    controlFlowGraph->newBasicBlock();
    // ex : .L3 if there is a else, .L2 otherwise
    controlFlowGraph->addIRInstr(IRInstr(LABEL,{to_string(labelNextBlock)}));

    // Prepare label for next if
    // ex : .L4
    controlFlowGraph->setLastLabel(labelNextBlock+1);
*/
    return "";
}


void If::print(std::ostream &stream) const
{
    stream << " If: Condition=" << *condition << *block;
    if(hasElse)
    {
        stream << *anElse << endl;
    }
}

std::ostream& operator<<(std::ostream& stream, const If& anIf)
{
    stream << " If: Condition=" << *anIf.condition << *anIf.block << endl;
    if(anIf.hasElse)
    {
        stream << *anIf.anElse << endl;
    }
    
    return stream;
}


void If::setElse(Else *anElse)
{
    this->anElse = anElse;
    this->hasElse = true;
}



If::If(Expression* condition, Block* block)
{
    this->condition = condition;
    this->block = block;
}

If::~If()
{
}
