using namespace std;

#include "If.h"
#include <iostream>
#include <string>
#include "./IR/BasicBlock.h"


string If::generateIR(CFG * cfg)
{
    // condition IR generation
    string conditionRes = condition->generateIR(cfg);

    // BasicBlocks creation and linking
    
    BasicBlock* thenBB = new BasicBlock(cfg, to_string(cfg -> next_BB_number()));
    BasicBlock* elseBB;
    if (hasElse){
    	elseBB = new BasicBlock(cfg, to_string(cfg -> next_BB_number()));
    }
    BasicBlock* afterBB = new BasicBlock(cfg, to_string(cfg -> next_BB_number()));

    // afterBB
    afterBB -> set_exit_true( cfg-> current_bb -> get_exit_true());
    afterBB -> set_exit_false ( cfg-> current_bb -> get_exit_false());
    
    cfg -> current_bb -> set_exit_true(thenBB);
    if (hasElse){
        cfg -> current_bb -> set_exit_false(elseBB);
    }else{
    	cfg -> current_bb -> set_exit_false(afterBB);
    }
    
    //thenBB
    thenBB -> set_exit_true(afterBB);
     
    //elseBB
    if (hasElse){
        elseBB -> set_exit_true(afterBB);
    }
    //add BBs in the table
    cfg -> addBB(thenBB);    
    
    // IR Generation and currentBB update
    cfg -> current_bb = thenBB;
    string blockRes = block->generateIR(cfg);

    if (hasElse){
        cfg -> addBB(elseBB);
        cfg -> current_bb = elseBB;
	string elseRes = anElse->generateIR(cfg);
    }

    cfg -> addBB(afterBB);
    cfg -> current_bb = afterBB;

    return "";
}


void If::print(std::ostream &stream) const
{
    stream << " If: Condition=" << *condition << *block;
    if(hasElse)
    {
        stream << endl << *anElse << endl;
    }
}

std::ostream& operator<<(std::ostream& stream, const If& anIf)
{
    stream << " If: Condition=" << *anIf.condition << *anIf.block ;
    if(anIf.hasElse)
    {
        stream << endl << *anIf.anElse << endl;
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

If::~If(){}
