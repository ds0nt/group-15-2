#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateRushToEnd :
	public AIState
{
public:
	StateStrategy* stateMachine;
	AIStateRushToEnd(StateStrategy* stateMachine);
	~AIStateRushToEnd(void);
	void doTurn(Player player);
	void onBoardChange();
};
