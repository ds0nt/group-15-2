#include "AIStateAngry.h"

AIStateAngry::AIStateAngry(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	//this->stateMachine = 
	printf("IN NEW STATE ANGRY HAHHAHHAHAHHAHHAHHAHA!\n");
}

AIStateAngry::~AIStateAngry(void)
{

}

void AIStateAngry::doTurn(Player p)
{
	printf("I made the move there!!! yeSS!!!!!!!!!!!!!!!!!!!! HAHAHHAHAHHAHAH!!!! \n");
	this->stateMachine->setState(ST_REGULAR);
}

void AIStateAngry::onBoardChange()
{
	printf("target AI got the Board Update I GOT THE UPDATE !!!!\n");

}