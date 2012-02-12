#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
class StateStrategy;
class AIStateAngry :
	public AIState
{
private:
	int emotion;
	int numberOfTurns;
	int ableToMovePiece;
public:
	StateStrategy* stateMachine;
	AIStateAngry(StateStrategy* stateMachine);
	~AIStateAngry(void);
	void doTurn(Player p);
	void onBoardChange();
	//void setEmotion(int);
	//int getEmotion();
};
