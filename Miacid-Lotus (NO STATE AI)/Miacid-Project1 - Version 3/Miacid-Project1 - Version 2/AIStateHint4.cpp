#include "AIStateHint4.h"
AIStateHint4::AIStateHint4(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State4 -- Make High Stack\n");
}


AIStateHint4::~AIStateHint4(void)
{
	
}

//Attack the enemy player if we can!
//Otherwize... do something unintelligable.

//Moved -> State 7
//Cannot Move -> SkipTurn, State 7
void AIStateHint4::doTurn(Player player)
{	
	move m = boardCalc::getMoveStackHighest(player.piece);
	if(!m.isNull())
	{
		GameData()->board.MovePiece(m.beginpos, m.endpos);
	}

	this->stateMachine->setState(ST_HINT_7);
}


//Cannot Move -> State 6
//Cannot Make Stack Anymore -> State 7

void AIStateHint4::onBoardChange()
{
	PIECE p = this->stateMachine->player->piece;
	
	if(!boardCalc::canMove(p))
	{
		this->stateMachine->setState(ST_HINT_6);
		return;
	}
	
	if(!boardCalc::getMoveStackHighest(p).isNull())
		return;

	this->stateMachine->setState(ST_HINT_7);

}
