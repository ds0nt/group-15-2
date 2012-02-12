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
	vector<int> angerMoves = vector<int>();
	for (int i = 0; i < moves.size(); i++)
	{
		printf("| %d, %d ", moves.at(i).beginpos, moves.at(i).endpos);
	}
	printf("|\n");
}

void AIStateVengeful::onBoardChange()
{
	//We dont give up until we kick some butt.
}
