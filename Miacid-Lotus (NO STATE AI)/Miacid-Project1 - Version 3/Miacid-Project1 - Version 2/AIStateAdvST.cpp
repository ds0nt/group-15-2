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
	vector<int> possibleActiveMoves;
	
	/*for (int i = 0; i < MAX_GAME_POSITIONS; i++)
	{
		if (GameData() -> board.IsPieceOnTop(player.piece, i));
			possibleActiveMoves.push_back(i);
	}*/

	if (GameData()->board.GetSizeOfStack(possibleActiveMoves.at(7) == 3))
	{
		printf("#####Weeeee~~#####\n");
		GameData()->board.MovePiece(3,-1);
	}
	else if (GameData()->board.GetSizeOfStack(possibleActiveMoves.at(6) == 4))
	{
		printf("#####Weeeee~~#####\n");
		GameData()->board.MovePiece(4,-1);
	}

}

void AIStateAdvST::onBoardChange()
{
	printf("AI just loves Springtile...!!! -_-\n");	
	//this->stateMachine->setState(ST_REGULAR);
}
