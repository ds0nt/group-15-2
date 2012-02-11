#include "AIStateRushToEnd.h"
AIStateRushToEnd::AIStateRushToEnd(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
}

//This is the Regular State
//
//

AIStateRushToEnd::~AIStateRushToEnd(void)
{

}

//move closest piece towards end!

void AIStateRushToEnd::doTurn(Player player)
{
	for (int i = MAX_GAME_POSITIONS-1; i >= MAX_GAME_POSITIONS-3; i--)
	{
		if(GameData()->board.IsPieceOnTop(this->stateMachine->player->piece, i))
		{
			GameData()->board.MovePiece(i, -1);
			return;
		}
	}
}

void AIStateRushToEnd::onBoardChange()
{
	for (int i = MAX_GAME_POSITIONS-1; i >= MAX_GAME_POSITIONS-3; i--)
	{
		if(GameData()->board.IsPieceOnTop(this->stateMachine->player->piece, i))
		{
			return;
		}
	}
	this->stateMachine->setState(ST_REGULAR);
}
