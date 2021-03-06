#include "AIStateAngry.h"

AIStateAngry::AIStateAngry(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;

	emotion = 0;
	numberOfTurns = 0;
	
	vector<move> moves = GameData()->board.getPossibleMoves(this->stateMachine->player->piece);
	
	vector<move> noDuplicateMoves;
	for(int i = 0; i < moves.size(); i++)
	{
		if (i == 0)
			noDuplicateMoves.push_back(moves.at(i));
		if (!(i == 0) && !(moves.at(i - 1).beginpos == moves.at(i).beginpos))
			noDuplicateMoves.push_back(moves.at(i));
	}
	
	ableToMovePiece = noDuplicateMoves.size();

	cout<<"current available piece in the initaliizing the angry state is: "<<ableToMovePiece<<endl;

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
			cout<<"I attack All of you!! General Attack go!!!!!!!!"<<endl;
			GameData()->board.MovePiece(moves.at(i).beginpos, moves.at(i).endpos);
			numberOfTurns++;


			//Here keep a track of my available piece to calculate Emotion.
			moves = GameData()->board.getPossibleMoves(player.piece);
			vector<move> noDuplicateMoves;

			for(int i = 0; i < moves.size(); i++)
			{
				if (i == 0)
					noDuplicateMoves.push_back(moves.at(i));
				if (!(i == 0) && !(moves.at(i - 1).beginpos == moves.at(i).beginpos))
					noDuplicateMoves.push_back(moves.at(i));
			}
			
			ableToMovePiece = noDuplicateMoves.size();
			return;
			//break;
		}
	}	
	
	int randomMove = rand() % moves.size();
	GameData()->board.MovePiece(moves.at(randomMove).beginpos, moves.at(randomMove).endpos);
	numberOfTurns++;





	//Here keep a track of my available piece to calculate Emotion.
	moves = GameData()->board.getPossibleMoves(player.piece);
	vector<move> noDuplicateMoves;

	for(int i = 0; i < moves.size(); i++)
	{
		if (i == 0)
			noDuplicateMoves.push_back(moves.at(i));
		if (!(i == 0) && !(moves.at(i - 1).beginpos == moves.at(i).beginpos))
			noDuplicateMoves.push_back(moves.at(i));
	}
	
	ableToMovePiece = noDuplicateMoves.size();
	return;
}


void AIStateAngry::onBoardChange()
{
	printf("target AI got the Board Update I GOT THE UPDATE !!!! AND I'm ANGRY!!!!!!!!!!!!!\n");
	//if AI got attack!!?!? 

	vector<move> moves = GameData()->board.getPossibleMoves(this->stateMachine->player->piece);//getting all possible moves.
	vector<move> noDuplicateMoves;

	for(int i = 0; i < moves.size(); i++)
	{
		if(i == 0)
			noDuplicateMoves.push_back(moves.at(i));
		if (!(i == 0) && !(moves.at(i -1).beginpos == moves.at(i).beginpos))
			noDuplicateMoves.push_back(moves.at(i));
	}


	cout<<"emotion                     : "<<emotion<<endl;
	cout<<"noDuplicateMoves	           : "<<noDuplicateMoves.size()<<endl;
	cout<<"ableToMove in Privious turn : "<<ableToMovePiece<<endl;
	cout<<"numberOfTurns               : "<<numberOfTurns<<endl;
	if (noDuplicateMoves.size() < ableToMovePiece)
	{
		cout<<"I got attack!?!?!?!>!>!>"<<endl;
		ableToMovePiece--;
		emotion++;
	}


	if (emotion == 2)
		this->stateMachine->setState(ST_VENGEFUL);
	if (numberOfTurns > 3)
		this->stateMachine->setState(ST_REGULAR);
	
}
