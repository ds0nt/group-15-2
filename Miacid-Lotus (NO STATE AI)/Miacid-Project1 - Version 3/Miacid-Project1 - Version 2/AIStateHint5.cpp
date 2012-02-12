#include "AIStateHint5.h"
AIStateHint5::AIStateHint5(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State5\n");
}

//This is the Regular State
//
//

AIStateHint5::~AIStateHint5(void)
{
	
}

//So just.. move random stuff? If it is size 1!
//Otherwize... do something unintelligable.

void AIStateHint5::doTurn(Player player)
{	
	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);

	//BOARD CHANGE CHECKS IF WE R BEING NAUGHTY BY HAVING BIG STACKSAAA!!

	//Default To Move Random Stuffs!
	if(moves.size() > 0)
	{	
		printf("State6 Go!");
		Sleep(1000);
		int i = GameData()->randInt(0, moves.size()-1);
		GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
	}

	//Otherwise skip turn
}

void AIStateHint5::onBoardChange()
{
	//OMG IT MUST BE OF SIZE 1 OR WE ARE BEING NAUTTY!!!!!!
	vector<move> moves = GameData()->board.getPossibleMoves(this->stateMachine->player->piece);
	for(int i = 0; i < moves.size(); i++)
		if(moves.at(i).endpos - moves.at(i).beginpos > 1)
			this->stateMachine->setState(ST_HINT_1); //PEACE OUT BRO
}
