#include "AIStateHint4.h"
AIStateHint4::AIStateHint4(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State4\n");
}

//This is the Regular State
//
//

AIStateHint4::~AIStateHint4(void)
{
	
}

//Attack the enemy player if we can!
//Otherwize... do something unintelligable.

void AIStateHint4::doTurn(Player player)
{	
	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);
	int highest = 1; //so that it is 2 or more
	move bestmove = move(-1,-1);


	//get good moves
	for (int i = 0; i < moves.size(); i++)
	{
		move m = moves.at(i);
		int size = GameData()->board.GetSizeOfStack(m.endpos);
		if(size > highest)
		{
			highest = size;	
			bestmove.beginpos = m.beginpos;
			bestmove.endpos = m.endpos;
		}
	}

	if(bestmove.endpos != -1)
	{
		GameData()->board.MovePiece(bestmove.beginpos, bestmove.endpos);
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

void AIStateHint4::onBoardChange()
{
}
