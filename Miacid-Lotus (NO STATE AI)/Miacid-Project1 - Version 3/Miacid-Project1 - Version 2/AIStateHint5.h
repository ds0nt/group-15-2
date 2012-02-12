#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateHint5 :
	public AIState
{
public:
	StateStrategy* stateMachine;
	AIStateHint5(StateStrategy* stateMachine);
	~AIStateHint5(void);
	void doTurn(Player player);
	void onBoardChange();
};
