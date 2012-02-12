#include "AIStateHint6.h"
AIStateHint6::AIStateHint6(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State6\n");
}

//This is the Regular State
//
//

AIStateHint6::~AIStateHint6(void)
{
	
}

//Attack the enemy player if we can!
//Otherwize... do something unintelligable.

void AIStateHint6::doTurn(Player player)
{	

	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);
	
	//Default To Move Random Stuffs!
	if(moves.size() > 0)
	{
		int i = GameData()->randInt(0, moves.size()-1);
		GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
		return;
	}

    
	//Get our deepest piece move list.
	moves = GameData()->board.getDeepestPiecesMoves(player.piece);
	
	int randomMove = GameData()->randInt(0, moves.size()-1);
	GameData()->board.MovePiece(moves.at(randomMove).beginpos, moves.at(randomMove).endpos);
	

	//Otherwise skip turn
}

void AIStateHint6::onBoardChange()
{
	//vector<move> moves = GameData()->board.getPossibleMoves(this->stateMachine->player->piece);
	//if(moves.size() == 0)
	//	this->stateMachine->setState(ST_HINT_1);
}
