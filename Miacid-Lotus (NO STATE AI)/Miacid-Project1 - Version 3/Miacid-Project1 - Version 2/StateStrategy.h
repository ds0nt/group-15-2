#pragma once
#include <vector>
#include "AIState.h"
#include "AIStateRegular.h"
#include "AIStateAngry.h"
#include "AIStateRushToEnd.h"
#include "AIStateVengeful.h"


#include "AIStateHint1.h"
#include "AIStateHint2.h"
#include "AIStateHint3.h"
#include "AIStateHint4.h"
#include "AIStateHint5.h"
#include "AIStateHint6.h"
#include "AIStateHint7.h"

#include "AIStrategy.h"


#include "foundation.h"

enum STATETYPE {
	ST_HINT_1, ST_HINT_2, ST_HINT_3, ST_HINT_4, ST_HINT_5, ST_HINT_6, ST_HINT_7,
	ST_REGULAR, ST_ANGRY, ST_RUSH_TO_END, ST_VENGEFUL
};

class StateStrategy : public AIStrategy
{
private:
	AIState* currentState;

public:
	Player* player;
	StateStrategy(Player* p, STATETYPE defaultState);
	~StateStrategy();
	void onBoardChange();
	void doTurn(Player p);
	void setState(STATETYPE newState);
};