#include "StateStrategy.h"

StateStrategy::StateStrategy(Player* p, STATETYPE defaultState)
{
	this->player = p;
	this->currentState = 0;
	this->setState(defaultState);
}

void StateStrategy::setState(STATETYPE newState)
{
	if(currentState != 0)
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
	case ST_VENGEFUL:
		this->currentState = new AIStateVengeful(this);
		break;
	case ST_HINT_1:
		this->currentState = new AIStateHint1(this);
		break;
	case ST_HINT_2:
		this->currentState = new AIStateHint2(this);
		break;
	case ST_HINT_3:
		this->currentState = new AIStateHint3(this);
		break;
	case ST_HINT_4:
		this->currentState = new AIStateHint4(this);
		break;
	case ST_HINT_5:
		this->currentState = new AIStateHint5(this);
		break;
	case ST_HINT_6:
		this->currentState = new AIStateHint6(this);
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
