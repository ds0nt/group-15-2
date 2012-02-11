#include "AIStateRushToEnd.h"
AIStateRushToEnd::AIStateRushToEnd(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("IN NEW STATE AIStateRushToEnd!\n");
}

//This is the Regular State
//
//

AIStateRushToEnd::~AIStateRushToEnd(void)
{

}

void AIStateRushToEnd::doTurn(Player player)
{
	printf("rush to end!!!!!!!!\n");
}

void AIStateRushToEnd::onBoardChange()
{
}
