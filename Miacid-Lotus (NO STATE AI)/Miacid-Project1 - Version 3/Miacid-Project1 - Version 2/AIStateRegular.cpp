#include "AIStateRegular.h"

AIStateRegular::AIStateRegular(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;

	printf("IN NEW STATE REGULAR!\n");
	emotion = 0;
}

//This is the Regular State
//
//

AIStateRegular::~AIStateRegular(void)
{

}

void AIStateRegular::doTurn(Player player)
{	
	
	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);
	for(int i=0; i< moves.size();i++)
	{
		if((GameData()->board.IsPieceOnTop(player.piece, moves.at(i).endpos)) || (GameData()->board.GetSizeOfStack(moves.at(i).endpos) == 0))
		{
			GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
			return;
		}
		if(moves.at(i).endpos ==  LOTUS_TRAMPOLINE)
		{
			int land = 2*(i - moves.at(i).beginpos);
			
			if(!(GameData()->board.IsPieceOnTop(player.piece, land)))
			{
				int select;
				srand((unsigned)time(0));
				select = rand()%moves.size()+1;
				GameData()->board.MovePiece(select, -1);
				return;
			}
			
			else
			GameData()->board.MovePiece(moves.at(i).beginpos,land);
			return;
		}
	}

	
	
}

void AIStateRegular::onBoardChange()
{
	if(GameData()->board.IsPieceOnTop(this->stateMachine->player->piece, MAX_GAME_POSITIONS-1))
	{
		this->stateMachine->setState(ST_RUSH_TO_END);
		return;
	}
	if(GameData()->board.IsPieceOnTop(this->stateMachine->player->piece, MAX_GAME_POSITIONS-2))
	{	
		this->stateMachine->setState(ST_RUSH_TO_END);
		return;
	}
	if(GameData()->board.IsPieceOnTop(this->stateMachine->player->piece, MAX_GAME_POSITIONS-3))
	{	
		this->stateMachine->setState(ST_RUSH_TO_END);
		return;
	}
	printf("Board Update while AI is in REGULAR STATE!!!!\n");
	emotion++;
	cout<<emotion<<endl;
	if (emotion >= 3)
		this->stateMachine->setState(ST_ANGRY);
}
