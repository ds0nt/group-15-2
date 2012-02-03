#include "foundation.h"
#include <vector>

class RuleStrategy : AIStrategy
{
public:
	void onBoardChange();
	void doTurn(Player p); 
};