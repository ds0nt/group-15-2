#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateAdvST :
	public AIState
{
public:
	StateStrategy* stateMachine;
	AIStateAdvST(StateStrategy* stateMachine);
	~AIStateAdvST(void);
	void doTurn(Player player);
	void onBoardChange();
};
