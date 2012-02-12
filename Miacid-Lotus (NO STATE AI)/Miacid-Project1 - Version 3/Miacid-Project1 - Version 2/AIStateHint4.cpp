#include "AIStateHint4.h"
AIStateHint4::AIStateHint4(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State4\n");
}

//This is the Regular State
//
//

AIStateHint4::~AIStateHint4(void)
{
	
}

//Attack the enemy player if we can!
//Otherwize... do something unintelligable.

void AIStateHint4::doTurn(Player player)
{	

}

void AIStateHint4::onBoardChange()
{
	PIECE p = this->stateMachine->player->piece;

}
