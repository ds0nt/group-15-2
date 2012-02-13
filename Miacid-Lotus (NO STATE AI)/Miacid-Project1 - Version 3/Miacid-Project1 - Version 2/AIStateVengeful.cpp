#include "AIStateVengeful.h"
AIStateVengeful::AIStateVengeful(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	//int target;
	if ((GameData()->players.at(GameData()->currentPlayer).piece - 1) == 0)
	{
		gettinSum = GameData()->players.at(GameData()->numplayers-1).piece;
	}
	else
		gettinSum = GameData()->players.at(GameData()->currentPlayer - 1).piece;
	//this->gettinSum = GameData()->players.at(GameData()->currentPlayer - 1).piece;
	this->enactedCount = 0;
	cout<<"\nI'm Vengeful!! i'll target a specific player and only attack that guy!!\n"<<endl;
	cout<<"\nI attacked "<<this->gettinSum<<" guy "<<this->enactedCount<<" times\n"<<endl;
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
	cout<<"got here"<<this->gettinSum<<endl;
	cout<<"And I am"<<this->stateMachine->player->piece<<endl;
	for (int i = 0; i < moves.size(); i++)
	{
		if(GameData()->board.IsPieceOnTop(this->gettinSum, moves.at(i).endpos))
		{
			cout<<"got here tOOOOOOOOOOOOOOOOOOOOOOOOOO"<<endl;
			GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
			this->enactedCount++;
			cout<<"\nI attacked "<<this->gettinSum<<" guy "<<this->enactedCount<<" times\n"<<endl;
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
	if(this->enactedCount > 1)
		this->stateMachine->setState(ST_REGULAR);
}
