#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateHint3 :
	public AIState
{
public:
	StateStrategy* stateMachine;
	AIStateHint3(StateStrategy* stateMachine);
	~AIStateHint3(void);
	void doTurn(Player player);
	void onBoardChange();
};
