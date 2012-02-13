#include "AIStateAdvST.h"
AIStateAdvST::AIStateAdvST(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("********************IN Advance Springtile!******************\n");
}

//This is the Regular State
//
//

AIStateAdvST::~AIStateAdvST(void)
{

}

//move closest piece towards end!

void AIStateAdvST::doTurn(Player player)
{
	printf("#############Doing AdvSpringTile move!!!#############\n");
	Sleep(1000);
	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);
	/*for (int i = 0; i < moves.size(); i++)
	{
		if(moves.at(i).endpos == 6 || moves.at(i).endpos== 7) // if lands 3 or 4 steps before trampoline
			if(moves.at(i).beginpos >= 6 && moves.at(i).beginpos <= 8) // if lands on trampoline
			{
				GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
				return;
			}
	}*/
	for (int i = 0; i < moves.size(); i++)
	{
		if (moves.at(i).endpos == 10 && (GameData()->board.GetSizeOfStack(moves.at(i).beginpos) == 4 || GameData()->board.GetSizeOfStack(moves.at(i).beginpos) == 3))
		{
			GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
			return;
		}
	}
	/*for (int i = 0; i < moves.size(); i++)
	{
		GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
		return;
	}*/
}

void AIStateAdvST::onBoardChange()
{
	printf("@@@@@@@@@@AI had(or used) a chance of going to Springtile...@@@@@@@@@@\n");	
	this->stateMachine->setState(ST_REGULAR);
}
