#pragma once
#include "StateStrategy.h"
#include "AIState.h"
#include "foundation.h"
#include "player.h"
class StateStrategy;
class AIStateRegular :
	public AIState
{
private:
	int emotion;
	int ableToMovePiece;
	//Player thisPlayer;

public:
	StateStrategy* stateMachine;
	AIStateRegular(StateStrategy* stateMachine);
	~AIStateRegular(void);
	void doTurn(Player p);
	void onBoardChange();
	//void setEmotion(int);
	//int getEmotion();
};
