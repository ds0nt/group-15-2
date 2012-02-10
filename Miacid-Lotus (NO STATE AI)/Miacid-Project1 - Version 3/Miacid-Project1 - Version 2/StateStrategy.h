#pragma once
#include <vector>
#include "AIStrategy.h"
#include "foundation.h"


class StateStrategy : public AIStrategy
{
public:
	StateStrategy(){};
	void onBoardChange();
	void doTurn(Player p); 

	
};