#pragma once
#include "AIState.h"
#include "foundation.h"

class AIStateRegular :
	public AIState
{
public:
	AIStateRegular(void);
	~AIStateRegular(void);
	void doTurn(Player p);
	void onBoardChange();
};
