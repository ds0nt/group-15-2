#include "AIStateHint5.h"
AIStateHint5::AIStateHint5(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State5\n");
}

//This is the Regular State
//
//

AIStateHint5::~AIStateHint5(void)
{
	
}

//So just.. move random stuff? If it is size 1!
//Otherwize... do something unintelligable.

void AIStateHint5::doTurn(Player player)
{	

}

void AIStateHint5::onBoardChange()
{
	PIECE p = this->stateMachine->player->piece;

}
