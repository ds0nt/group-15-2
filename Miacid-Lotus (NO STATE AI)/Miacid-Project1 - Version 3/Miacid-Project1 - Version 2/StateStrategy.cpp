#include "StateStrategy.h"

StateStrategy::StateStrategy()
{
	this->currentState = new AIStateRegular();
}

void StateStrategy::setState(AIState* state)
{
	delete this->currentState;
	this->currentState = state;
}
StateStrategy::~StateStrategy()
{
	delete this->currentState;
}

void StateStrategy::onBoardChange()
{
	this->currentState->onBoardChange();
}

void StateStrategy::doTurn(Player player)
{
	this->currentState->doTurn(player);
}
