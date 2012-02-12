#include "AIStateAngry.h"

AIStateAngry::AIStateAngry(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;
	//this->stateMachine = 
	//this->gettinSum = GameData()->players.at(GameData()->currentPlayer).piece;
	printf("IN NEW STATE ANGRY HAHHAHHAHAHHAHHAHHAHA!\n");
	emotion = 0;
	numberOfTurns = 0;
	//ableToMovePiece = 0;
}

AIStateAngry::~AIStateAngry(void)
{

}

void AIStateAngry::doTurn(Player player)
{
	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);//getting all possible moves.
	for (int i = 0; i < moves.size(); i++)	//so till there is things to move!
	{
		printf("%d, %d |", moves.at(i).beginpos, moves.at(i).endpos); //able to move piece!
		
		if(!(GameData()->board.IsPieceOnTop(this->stateMachine->player->piece, moves.at(i).endpos)) && (GameData()->board.GetTopPiece(moves.at(i).endpos) != 0))
		{
			cout<<"AHHASHHHHHHHHHHHHHHHHHHHHHHHHH"<<endl;
			GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
			numberOfTurns++;
			return;
		}
	}	
	
	int randomMove = rand() % moves.size();
	GameData()->board.MovePiece(moves.at(randomMove).beginpos, moves.at(randomMove).endpos);
	numberOfTurns++;
	return;
}


void AIStateAngry::onBoardChange()
{
	printf("target AI got the Board Update I GOT THE UPDATE !!!! AND I'm ANGRY!!!!!!!!!!!!!\n");
	//if AI got attack!!?!? 
	vector<int> possibleStartMoves;
	for (int i = -1; i >= -GameData()->board.numstartstacks; i--)
	{
		if (GameData()->board.IsPieceOnTop(this->stateMachine->player->piece, i))
		{
			possibleStartMoves.push_back(i);
		}
	}

	
	vector<int> possibleActiveMoves;
	for (int i = 0; i < MAX_GAME_POSITIONS; i++)
	{
		if (GameData()->board.IsPieceOnTop(this->stateMachine->player->piece, i))
		{

			possibleActiveMoves.push_back(i);
		}
	}
	//if (!(possibleStartMoves.empty()))
	//	ableToMovePiece++;
	if (possibleActiveMoves.size() <= ableToMovePiece)
		emotion++;
	//else
	//	emotion--;
	

	cout<<emotion<<endl;
	cout<<possibleActiveMoves.size()<<endl;
	cout<<numberOfTurns<<endl;
	//cout<<typeid(this).name()<<endl;
	//if (emotion == 2)
	//	this->stateMachine->setState(ST_VENGEFUL);
	if (numberOfTurns > 3)
		this->stateMachine->setState(ST_REGULAR);
	
}
