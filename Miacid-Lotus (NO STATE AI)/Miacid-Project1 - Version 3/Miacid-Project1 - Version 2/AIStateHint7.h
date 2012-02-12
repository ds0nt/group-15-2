#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateHint7 :
	public AIState
{
public:
	StateStrategy* stateMachine;
	AIStateHint7(StateStrategy* stateMachine);
	~AIStateHint7(void);
	void doTurn(Player player);
	void onBoardChange();
};
