#include "AIStateHint3.h"
AIStateHint3::AIStateHint3(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State3 -- SET BOUNCE\n");
}

//This is the Regular State
//
//

AIStateHint3::~AIStateHint3(void)
{
	
}

//Attack the enemy player if we can!
//Otherwize... do something unintelligable.

void AIStateHint3::doTurn(Player player)
{	
	
}

void AIStateHint3::onBoardChange()
{
	PIECE p = this->stateMachine->player->piece;

}
