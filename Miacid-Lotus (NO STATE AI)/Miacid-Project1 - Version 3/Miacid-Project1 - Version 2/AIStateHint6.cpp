#include "AIStateHint6.h"
AIStateHint6::AIStateHint6(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State6 -- Move Enemy!\n");
}

//This is the Regular State
//
//

AIStateHint6::~AIStateHint6(void)
{

	
}

//Attack the enemy player if we can!
//Otherwize... do something unintelligable.

//MOVE BADDY
//Stay in this state until we watch the board :)

void AIStateHint6::doTurn(Player player)
{
	move m = boardCalc::getMoveUncoverDeepest(player.piece);
	if(!m.isNull())
		GameData()->board.MovePiece(m.beginpos, m.endpos);

}


//Can Move -> State 7
void AIStateHint6::onBoardChange()
{
	PIECE p = this->stateMachine->player->piece;
	
	if(boardCalc::canMove(p))
	{
		this->stateMachine->setState(ST_HINT_7);
		return;
	}
}
