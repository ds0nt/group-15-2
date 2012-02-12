#include "AIStateHint2.h"
AIStateHint2::AIStateHint2(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State2 -- Use Trampoline\n");
}

//This is the Regular State
//
//

AIStateHint2::~AIStateHint2(void)
{
	
}

//Attack the enemy player if we can!
//Otherwize... do something unintelligable.



//Moved, Can Bounce Again -> Stay This State
//Moved, Cannot Bounce, Can Set -> State 3
//Moved, Cannot Bounce, Cannot Set, Can Stack -> State 4
//Moved, Cannot Bounce, Cannot Set, Cannot Stack -> State 7
void AIStateHint2::doTurn(Player player)
{	
	move m = boardCalc::getMoveBigBounce(player.piece);
	
	if(!m.isNull())
		GameData()->board.MovePiece(m.beginpos, m.endpos);
	
	//great success -> now keep going or make a high stack, or go back to normal

	if(!boardCalc::getMoveBigBounce(player.piece).isNull())
		return;

	if(!boardCalc::getMoveSetBounce(player.piece).isNull())
	{
		this->stateMachine->setState(ST_HINT_3);
		return;
	}

	if(!boardCalc::getMoveStackHighest(player.piece).isNull())
	{
		this->stateMachine->setState(ST_HINT_4);
		return;
	}

	this->stateMachine->setState(ST_HINT_7);
}

//Cannot Bounce && Cannot Set Bounce -> State 7
//Cannot Bounce && Can Set Bounce -> State 3
//Can Still Big Bounce -> Dont Change
void AIStateHint2::onBoardChange()
{
	PIECE p = this->stateMachine->player->piece;
	
	if(boardCalc::getMoveBigBounce(p).isNull())
	{
		if(boardCalc::getMoveSetBounce(p).isNull())
		{
			//cant set, cant bounce, go to standard move
			this->stateMachine->setState(ST_HINT_7);
		}
		//can set, go to set state
		this->stateMachine->setState(ST_HINT_3);
		return;
	}
	//stay in current state if we can still do big bounce.
}
