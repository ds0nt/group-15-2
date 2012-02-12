#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateHint1 :
	public AIState
{
public:
	StateStrategy* stateMachine;
	AIStateHint1(StateStrategy* stateMachine);
	~AIStateHint1(void);
	void doTurn(Player player);
	void onBoardChange();
};
