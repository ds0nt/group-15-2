#include "AIStateHint7.h"
AIStateHint7::AIStateHint7(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State7 -- Farthest Move\n");
}

AIStateHint7::~AIStateHint7(void)
{
	
}

//Standard move, Move as far as we can!
//50% go farthest, go random move
void AIStateHint7::doTurn(Player player)
{
	move m = MOVE_NULL;
	if(GameData()->randInt(0,1) == 1)
	{
		m = boardCalc::getFarthestMove(player.piece);
	}
	else
	{
		m = boardCalc::getRandomMove(player.piece);
	}
	if(!m.isNull())
		GameData()->board.MovePiece(m.beginpos, m.endpos);
}

//cant move -> state 6
//can rush end -> state 1
//can bounce -> state 2
//no tall stacks -> state 5
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

	m = boardCalc::getMoveBigBounce(p);
	if(!m.isNull())
	{
		this->stateMachine->setState(ST_HINT_2);
		return;
	}
	
	if(!boardCalc::getTallestStackSize(p) > 1)
	{
		this->stateMachine->setState(ST_HINT_5);
		return;
	}
}
