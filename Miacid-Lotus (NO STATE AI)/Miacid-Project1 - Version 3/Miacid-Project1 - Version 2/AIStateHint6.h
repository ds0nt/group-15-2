#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateHint6 :
	public AIState
{
public:
	StateStrategy* stateMachine;
	AIStateHint6(StateStrategy* stateMachine);
	~AIStateHint6(void);
	void doTurn(Player player);
	void onBoardChange();
};
