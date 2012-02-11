#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateRegular :
	public AIState
{
private:
	int emotion;
public:
	StateStrategy* stateMachine;
	AIStateRegular(StateStrategy* stateMachine);
	~AIStateRegular(void);
	void doTurn(Player p);
	void onBoardChange();
	//void setEmotion(int);
	//int getEmotion();
};
