#include "AIStateVengeful.h"
AIStateVengeful::AIStateVengeful(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	this->gettinSum = GameData()->players.at(GameData()->currentPlayer).piece;
	this->enactedCount = 0;
}

//This is the Regular State
//
//

AIStateVengeful::~AIStateVengeful(void)
{

}

//Attack the enemy player if we can!
//Otherwize... do something unintelligable.

void AIStateVengeful::doTurn(Player player)
{	
	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);
	for (int i = 0; i < moves.size(); i++)
	{
		printf("%d, %d |", moves.at(i).beginpos, moves.at(i).endpos);
		if(GameData()->board.IsPieceOnTop(this->gettinSum, moves.at(i).endpos))
		{
			GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
			this->enactedCount++;
			return;
		}
	}	
	//if theres none of his piece we can land on, just move something.
	for (int i = 0; i < moves.size(); i++)
	{
		GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
		return;
	}
	//Otherwise skip turn
}

void AIStateVengeful::onBoardChange()
{
	if(this->enactedCount > 2)
		this->stateMachine->setState(ST_REGULAR);
}
