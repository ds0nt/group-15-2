#include "AIStateHint7.h"
AIStateHint7::AIStateHint7(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State7 -- Random Move\n");
}

//This is the Regular State
//
//

AIStateHint7::~AIStateHint7(void)
{
	
}

//Standard move, just do random shit.

void AIStateHint7::doTurn(Player player)
{
	move m = boardCalc::getRandomMove(player.piece);
	if(!m.isNull())
		GameData()->board.MovePiece(m.beginpos, m.endpos);
}

//cant move -> state 6
//can rush end -> state 1

void AIStateHint7::onBoardChange()
{
	PIECE p = this->stateMachine->player->piece;
	
	if(!boardCalc::canMove(p))
	{
		this->stateMachine->setState(ST_HINT_6);
		return;
	}
	move m = boardCalc::getMoveToEnd(p);
	if(!m.isNull())
	{
		this->stateMachine->setState(ST_HINT_1);
		return;
	}

}
