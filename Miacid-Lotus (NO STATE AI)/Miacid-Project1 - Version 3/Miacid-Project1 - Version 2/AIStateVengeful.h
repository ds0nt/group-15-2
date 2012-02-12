#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateVengeful :
	public AIState
{
public:
	StateStrategy* stateMachine;
	PIECE gettinSum;
	int enactedCount;
	AIStateVengeful(StateStrategy* stateMachine);
	~AIStateVengeful(void);
	void doTurn(Player player);
	void onBoardChange();
};
