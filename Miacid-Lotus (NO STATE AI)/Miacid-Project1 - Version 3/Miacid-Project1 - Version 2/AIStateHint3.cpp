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


//Moved -> State 7
void AIStateHint3::doTurn(Player player)
{	
	move m = boardCalc::getMoveSetBounce(player.piece);
	
	if(!m.isNull())
		GameData()->board.MovePiece(m.beginpos, m.endpos);

	this->stateMachine->setState(ST_HINT_7);
}

//Cannot Move -> State 6
//Cannot Set -> State 7
void AIStateHint3::onBoardChange()
{
	PIECE p = this->stateMachine->player->piece;
	
	if(!boardCalc::canMove(p))
	{
		this->stateMachine->setState(ST_HINT_6);
		return;
	}
	
	if(!boardCalc::getMoveSetBounce(p).isNull())
		return;

	this->stateMachine->setState(ST_HINT_7);

}
