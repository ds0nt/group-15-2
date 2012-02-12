#include "AIStateAdvST.h"
AIStateAdvST::AIStateAdvST(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("*****IN Advance Springtile!*****\n");
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
	printf("doing advst move\n");
	Sleep(1000);
	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);
	for (int i = 0; i < moves.size(); i++)
	{
		if(moves.at(i).endpos == 10) // if lands on trampoline
			if(moves.at(i).beginpos >= 6 && moves.at(i).beginpos <= 8) // if lands on trampoline
			{
				GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
				return;
			}
	}
	for (int i = 0; i < moves.size(); i++)
	{
		GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
		return;
	}
}

void AIStateAdvST::onBoardChange()
{
	printf("AI just loves Springtile...!!! -_-\n");	
	this->stateMachine->setState(ST_REGULAR);
}
