#include "AIStateHint1.h"
AIStateHint1::AIStateHint1(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State1\n");
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
	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);
	vector<move> goodmoves = vector<move>();
	
	//get good moves
	for (int i = 0; i < moves.size(); i++)
	{
		if(moves.at(i).endpos >= 17)
		{
			goodmoves.push_back(moves.at(i));
		}
	}

	//do best good move
	//orders from front to back.
	for (int i = 0; i < goodmoves.size(); i++)
	{
		GameData()->board.MovePiece(goodmoves.at(i).beginpos, goodmoves.at(i).endpos);
		return;
	}
	
	
	//Default To Move Random Stuffs!
	if(moves.size() > 0)
	{
		int i = GameData()->randInt(0, moves.size()-1);
		GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
	}

	//Otherwise skip turn
}

void AIStateHint1::onBoardChange()
{
	this->stateMachine->setState(ST_HINT_6);
}
