#include "AIStateHint1.h"
AIStateHint1::AIStateHint1(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State1 -- Rush To End\n");
}

//This is the Regular State
//
//

AIStateHint1::~AIStateHint1(void)
{
	
}

//Race Our Pieces near the end to the exit!
void AIStateHint1::doTurn(Player player)
{
	move m = boardCalc::getMoveToEnd(player.piece);
	
	if(!m.isNull())
		GameData()->board.MovePiece(m.beginpos, m.endpos);
}

//Cannot Move ->  State 6
//Cannot Move To End -> State 7
void AIStateHint1::onBoardChange()
{
	PIECE p = this->stateMachine->player->piece;
	
	if(!boardCalc::canMove(p))
	{
		this->stateMachine->setState(ST_HINT_6);
		return;
	}
	move m = boardCalc::getMoveToEnd(p);
	if(m.isNull())
	{
		this->stateMachine->setState(ST_HINT_7);
		return;
	}
}
