#include "StateStrategy.h"

StateStrategy::StateStrategy()
{
	this->currentState = new AIStateRegular(this);
}

void StateStrategy::setState(STATETYPE newState)
{
	delete this->currentState;
	switch(newState)
	{
	case ST_REGULAR:
		this->currentState = new AIStateRegular(this);
		break;
	}
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
