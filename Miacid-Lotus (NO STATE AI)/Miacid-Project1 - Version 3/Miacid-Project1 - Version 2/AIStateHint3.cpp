#include "AIStateHint3.h"
AIStateHint3::AIStateHint3(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	printf("Changing to State3\n");
}

//This is the Regular State
//
//

AIStateHint3::~AIStateHint3(void)
{
	
}

//Attack the enemy player if we can!
//Otherwize... do something unintelligable.

void AIStateHint3::doTurn(Player player)
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
	vector<move> ourmoves = GameData()->board.getPossibleMoves(player.piece);
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
	for (int i = goodmoves.size() - 1; i >= 0; i--)
	{
		printf("good move\n");
		Sleep(1000);

		GameData()->board.MovePiece(goodmoves.at(i).beginpos, goodmoves.at(i).endpos);
		this->stateMachine->setState(ST_HINT_2);
		return;
	}
	
	
	//Default To Move Random Stuffs!
	if(ourmoves.size() > 0)
	{
		int i = GameData()->randInt(0, ourmoves.size()-1);
		GameData()->board.MovePiece(ourmoves.at(i).beginpos, ourmoves.at(i).endpos);
	}

	//Otherwise skip turn
}

void AIStateHint3::onBoardChange()
{
}
