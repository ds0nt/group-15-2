#include "AIStateRegular.h"

AIStateRegular::AIStateRegular(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("IN NEW STATE REGULAR!\n");
}

AIStateRegular::~AIStateRegular(void)
{

}

void AIStateRegular::doTurn(Player p)
{
	printf("Great Success!\n");
	this->stateMachine->setState(ST_REGULAR);
}

void AIStateRegular::onBoardChange()
{
	printf("Board Update\n");

}