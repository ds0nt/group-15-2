#include "StateStrategy.h"

StateStrategy::StateStrategy(Player* p)
{
	this->player = p;
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
	case ST_ANGRY:
		this->currentState = new AIStateAngry(this);
		break;
	case ST_RUSH_TO_END:
		this->currentState = new AIStateRushToEnd(this);
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
