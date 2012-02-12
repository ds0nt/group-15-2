#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateHint2 :
	public AIState
{
public:
	StateStrategy* stateMachine;
	AIStateHint2(StateStrategy* stateMachine);
	~AIStateHint2(void);
	void doTurn(Player player);
	void onBoardChange();
};
