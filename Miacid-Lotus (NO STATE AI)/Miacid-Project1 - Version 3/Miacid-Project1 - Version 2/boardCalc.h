#pragma once
#include "foundation.h"

class boardCalc
{
public:
	static move getMoveToEnd(PIECE p);
	static move getMoveBigBounce(PIECE p);
	static move getMoveSetBounce(PIECE p);
	static move getMoveStackHighest(PIECE p);
	static int getTallestStackSize(PIECE p);
	static move getRandomMove(PIECE p);
	static bool canMove(PIECE p);
	static move getMoveUncoverDeepest(PIECE p);
};
