#pragma once
#include <vector>
#include "AIStrategy.h"
#include "foundation.h"

class RuleStrategy : public AIStrategy
{
public:
	RuleStrategy(){};
	void onBoardChange();
	void doTurn(Player p); 
};