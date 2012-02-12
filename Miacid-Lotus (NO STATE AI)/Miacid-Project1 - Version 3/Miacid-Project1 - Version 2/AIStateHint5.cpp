#include "AIStateHint5.h"
AIStateHint5::AIStateHint5(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State5 -- Only Stacks of 1, Random Select\n");
}

//This is the Regular State
//
//

AIStateHint5::~AIStateHint5(void)
{
	
}

//So just.. move random stuff? If it is size 1!
//Otherwize... do something unintelligable.

//Moved, Stack of > 1 Exists -> State 7
//Moved, no >1 Stacks -> Stay in this State
void AIStateHint5::doTurn(Player player)
{	
	move m = boardCalc::getRandomMove(player.piece);
	if(!m.isNull())
		GameData()->board.MovePiece(m.beginpos, m.endpos);

	if(boardCalc::getTallestStackSize(player.piece) > 1)
	{
		this->stateMachine->setState(ST_HINT_7);
		return;
	}
}

//Cannot Move -> State 6
//Stack Taller Than 1 -> State 7
//Only Has Stacks of 1 -> This State
void AIStateHint5::onBoardChange()
{
	PIECE p = this->stateMachine->player->piece;
	
	if(!boardCalc::canMove(p))
	{
		this->stateMachine->setState(ST_HINT_6);
		return;
	}
	
	if(boardCalc::getTallestStackSize(p) > 1)
	{
		this->stateMachine->setState(ST_HINT_7);
		return;
	}
}
