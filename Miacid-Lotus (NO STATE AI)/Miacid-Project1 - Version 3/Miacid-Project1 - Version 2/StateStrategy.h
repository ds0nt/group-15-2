#pragma once
#include <vector>
#include "AIState.h"
#include "AIStateRegular.h"
#include "AIStateAngry.h"
#include "AIStateRushToEnd.h"
#include "AIStateVengeful.h"
#include "AIStateAdvST.h"
#include "AIStrategy.h"
#include "foundation.h"

enum STATETYPE {ST_REGULAR, ST_ANGRY, ST_RUSH_TO_END, ST_VENGEFUL, ST_ADVST};

class StateStrategy : public AIStrategy
{
private:
	AIState* currentState;

public:
	Player* player;
	StateStrategy(Player* p);
	~StateStrategy();
	void onBoardChange();
	void doTurn(Player p);
	void setState(STATETYPE newState);
};