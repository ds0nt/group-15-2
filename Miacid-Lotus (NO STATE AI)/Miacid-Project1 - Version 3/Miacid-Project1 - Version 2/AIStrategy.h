#include "foundation.h"
class Player;

class AIStrategy
{
public:
	virtual void onBoardChange() = 0;
	virtual void doTurn(Player p) = 0;
};