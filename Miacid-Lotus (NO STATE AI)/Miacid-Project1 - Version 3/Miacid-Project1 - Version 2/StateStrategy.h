#pragma once
#include <vector>
#include "AIState.h"
#include "AIStateRegular.h"
#include "AIStrategy.h"
#include "foundation.h"


class StateStrategy : public AIStrategy
{
private:
	AIState* currentState;

public:
	StateStrategy();
	~StateStrategy();
	void onBoardChange();
	void doTurn(Player p);
	void setState(AIState* newState);
};