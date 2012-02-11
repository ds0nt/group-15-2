#pragma once
#include "AIState.h"
#include "foundation.h"

class AIStateAngry :
	public AIState
{
public:
	AIStateAngry(void);
	~AIStateAngry(void);
	void doTurn(Player p);
	void onBoardChange();
};
