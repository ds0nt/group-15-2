#include "AIStateHint2.h"
AIStateHint2::AIStateHint2(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State2\n");
}

//This is the Regular State
//
//

AIStateHint2::~AIStateHint2(void)
{
	
}

//Attack the enemy player if we can!
//Otherwize... do something unintelligable.

void AIStateHint2::doTurn(Player player)
{	
	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);
	vector<move> goodmoves = vector<move>();
	
	//get good moves
	for (int i = 0; i < moves.size(); i++)
	{
		move m = moves.at(i);
		if(m.endpos == 10) //land on trampoline
		{
			if(m.endpos - m.beginpos >= 4) //distance of 4 or more
				goodmoves.push_back(m);
		}
	}

	//do closest to trampoline
	//orders from do end to begin.
	for (int i = goodmoves.size() - 1; i >= 0; i--)
	{

		GameData()->board.MovePiece(goodmoves.at(i).beginpos, goodmoves.at(i).endpos);
		
		this->stateMachine->setState(ST_HINT_1);
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

void AIStateHint2::onBoardChange()
{
}
