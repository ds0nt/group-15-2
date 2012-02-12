#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateHint4 :
	public AIState
{
public:
	StateStrategy* stateMachine;
	AIStateHint4(StateStrategy* stateMachine);
	~AIStateHint4(void);
	void doTurn(Player player);
	void onBoardChange();
};
