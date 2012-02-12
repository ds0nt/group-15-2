#include "AIStateRegular.h"

AIStateRegular::AIStateRegular(StateStrategy* stateMachine)
{
	this->stateMachine = stateMachine;

	printf("IN NEW STATE REGULAR!\n");
	emotion = 0;
	ableToMovePiece = 0;

}

//This is the Regular State
//
//

AIStateRegular::~AIStateRegular(void)
{

}

void AIStateRegular::doTurn(Player player)
{
	vector<move> moves = GameData()->board.getPossibleMoves(player.piece);//getting all possible moves.
	
	vector<move> okToMove; 
	

	
	for (int i = 0; i < moves.size(); i++)	//so till there is things to move!
	{
		printf("%d, %d |", moves.at(i).beginpos, moves.at(i).endpos); //able to move piece!
		
		if(!(GameData()->board.IsPieceOnTop(this->stateMachine->player->piece, moves.at(i).endpos)) && (GameData()->board.GetTopPiece(moves.at(i).endpos) != 0))
		{
			cout<<"It's not my piece!! I don't like to attack this guy yet cuz i'm kind!!!"<<endl;
			
		}
		else if(moves.at(i).endpos == 10)
		{
			int tempDis = GameData()->board.GetSizeOfStack(moves.at(i).beginpos);
			if (!(GameData()->board.IsPieceOnTop(this->stateMachine->player->piece, moves.at(i).endpos + tempDis)) &&  (GameData()->board.GetTopPiece(moves.at(i).endpos + tempDis) != 0))
				cout<<"\n\n OMG!! if I use Tramp, enemy will be covered!! i won't do that!!! \n\n"<<endl;
			else
				okToMove.push_back(moves.at(i));
		}
		else{
			okToMove.push_back(moves.at(i));
		}
		
	}	

	//
	//now make a random move thats NOT COVERING ENEMIES' PIECES!
	if (okToMove.size() != 0)
	{
		int randomMove = rand() % okToMove.size();
		cout<<"I move "<<okToMove.at(randomMove).beginpos<<","<<okToMove.at(randomMove).endpos<<endl;
		GameData()->board.MovePiece(okToMove.at(randomMove).beginpos, okToMove.at(randomMove).endpos);
	}
	else if (moves.size() != 0)
	{
		int randomMove = rand() % moves.size();
		cout<<"\n\nSO SORRY!!!!!!!!!!!!!!! I had no choice but U!!! Coord is"<<moves.at(randomMove).beginpos<<","<<moves.at(randomMove).endpos<<"\n\n"<<endl;
		GameData()->board.MovePiece(moves.at(randomMove).beginpos, moves.at(randomMove).endpos);
	}
	else // super NO CHOICE!!! I don't have any piece left to 
	{
		cout<<"\n\nI'll jsut SKIP the turn cuz i'm kind!!!\n\n"<<endl;
	}
	
	


	
	//here I need to keep a track of my availabe pieces.
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

	printf("\nBoard Update while AI is in REGULAR STATE!!!!\n");
	

	//testing
	this->stateMachine->setState(ST_VENGEFUL);
	return;
	//testing

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
	cout<<"noDuplicateMoves            : "<<noDuplicateMoves.size()<<endl;
	cout<<"ableToMove in Privious turn : "<<ableToMovePiece<<endl;
	if (noDuplicateMoves.size() < ableToMovePiece)
	{
		cout<<"I got attack!?!?!?!>!>!>"<<endl;
		ableToMovePiece--;
		emotion++;
	}

	if (emotion > 2)
		this->stateMachine->setState(ST_ANGRY);
}
