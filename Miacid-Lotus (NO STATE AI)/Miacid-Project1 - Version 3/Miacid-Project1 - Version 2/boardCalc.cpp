#include "boardCalc.h"

move boardCalc::getMoveToEnd(PIECE p)
{
	vector<move> moves = GameData()->board.getPossibleMoves(p);
	vector<move> goodmoves = vector<move>();
	
	//get good moves
	for (int i = 0; i < moves.size(); i++)
	{
		if(moves.at(i).endpos >= 17)
		{
			goodmoves.push_back(moves.at(i));
		}
	}

	//do best good move
	//orders from front to back.
	if(goodmoves.size() > 0)
		return goodmoves.at(0);
	return MOVE_NULL;
}
move boardCalc::getMoveBigBounce(PIECE p)
{
	vector<move> moves = GameData()->board.getPossibleMoves(p);
	vector<move> goodmoves = vector<move>();
	
	//get good moves
	for (int i = 0; i < moves.size(); i++)
	{
		move m = moves.at(i);
		if(m.endpos == 10) //land on trampoline
		{
			if(m.endpos - m.beginpos >= 4) //distance of 4 or more
				goodmoves.push_back(m);
		}
	}

	//do closest to trampoline
	//orders from do end to begin.

	if(goodmoves.size() > 0)
		return goodmoves.at(goodmoves.size()-1);
	return MOVE_NULL;
}
move boardCalc::getMoveSetBounce(PIECE p)
{
	vector<move> goodmoves = vector<move>();
	//search for any move that will land in front of trampoline and remember end points.
	vector<int> search = vector<int>();
	for(int si = 0; si < GameData()->numplayers; si++)
	{
		vector<move> moves = GameData()->board.getPossibleMoves(
			GameData()->players.at(si).piece
		);
		for (int i = 0; i < moves.size(); i++)
		{
			move m = moves.at(i);
			if(m.endpos == 9) //land on trampoline
			{
				if(m.endpos - m.beginpos >= 2) //distance of 2 or more
					search.push_back(m.beginpos);
			}
		}
	}

	//GET OUR MOVES THAT WILL LAND ON A POTENTIAL TRAMPOLINE!
	//All our valid moves
	vector<move> ourmoves = GameData()->board.getPossibleMoves(p);
	for (int i = 0; i < ourmoves.size(); i++)
	{
		move m = ourmoves.at(i);

		//We wanna land on one of those tiles
		for(int j = 0; j < search.size(); j++)
		{
			if(m.endpos == search.at(j)) //land on trampoline
			{
				goodmoves.push_back(m);
			}
		}
	}

	//Do the piece that is closest to start to setup that move.
	if(goodmoves.size() > 0)
		return goodmoves.at(goodmoves.size()-1);
	return MOVE_NULL;
}

//Pile it high!
move boardCalc::getMoveStackHighest(PIECE p)
{
	vector<move> moves = GameData()->board.getPossibleMoves(p);
	int highest = 1; //so that it is 2 or more
	move bestmove = move(-1,-1);


	//get good moves
	for (int i = 0; i < moves.size(); i++)
	{
		move m = moves.at(i);
		int size = GameData()->board.GetSizeOfStack(m.endpos);
		if(size > highest)
		{
			highest = size;	
			bestmove.beginpos = m.beginpos;
			bestmove.endpos = m.endpos;
		}
	}

	if(bestmove.endpos != -1)
		return bestmove;
	return MOVE_NULL;
}
int boardCalc::getTallestStackSize(PIECE p)
{
	vector<move> moves = GameData()->board.getPossibleMoves(p);
	int tallest = 1;
	for(int i = 0; i < moves.size(); i++)
		if(moves.at(i).endpos - moves.at(i).beginpos > tallest)
			tallest = moves.at(i).endpos - moves.at(i).beginpos;
	return tallest;
}
move boardCalc::getRandomMove(PIECE p)
{
	vector<move> moves = GameData()->board.getPossibleMoves(p);
	if(moves.size() > 0)
	{
		int i = GameData()->randInt(0, moves.size()-1);
		return moves.at(i);
	}
	return MOVE_NULL;

}
bool boardCalc::canMove(PIECE p)
{
	vector<move> moves = GameData()->board.getPossibleMoves(p);
	if(moves.size() > 0)
		return true;
	return false;
}
move boardCalc::getMoveUncoverDeepest(PIECE p)
{
	vector<move> moves = GameData()->board.getDeepestPiecesMoves(p);

	int randomMove = GameData()->randInt(0, moves.size()-1);
	return moves.at(randomMove);
}
