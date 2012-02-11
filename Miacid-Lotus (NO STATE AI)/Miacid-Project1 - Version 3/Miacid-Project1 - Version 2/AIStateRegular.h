#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateRegular :
	public AIState
{
public:
	StateStrategy* stateMachine;
	AIStateRegular(StateStrategy* stateMachine);
	~AIStateRegular(void);
	void doTurn(Player p);
	void onBoardChange();
};
