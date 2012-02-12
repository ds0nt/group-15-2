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
	vector<int> possibleActiveMoves;
	vector<int> possibleStartMoves;
//	thisPlayer = player;
	//possibleActiveMove = new vector<int>;
	
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
<<<<<<< HEAD
			ruleToFire = valid.at(i)->rulenum;
			topWeight = valid.at(i)->weight;
		}
	}

	bool moveUseful = 1; // assume the move was useful; tell us if it wasn't.
	TMove useMove = GameData()->Rules.at(ruleToFire).result;


	//find the active piece on the board.
	

	for (int i = 0; i < MAX_GAME_POSITIONS; i++)
	{
		if (GameData()->board.IsPieceOnTop(player.piece, i))
		{

			possibleActiveMoves.push_back(i);
		}
	}

	ableToMovePiece = possibleActiveMoves.size();


	

	for (int i = -1; i >= -GameData()->board.numstartstacks; i--)
	{
		if (GameData()->board.IsPieceOnTop(player.piece, i))
		{
			possibleStartMoves.push_back(i);
		}
	}


	//ableToMovePiece += possibleStartMoves.size();



	if (possibleActiveMoves.empty())
	{
		switch (useMove)
		{
			case TM_ATTACK:
			case TM_FORWARD:
				moveUseful = 0;
				useMove = TM_START;
			break;
		}
	}

	if (possibleStartMoves.empty())
	{
		switch (useMove)
		{
			case TM_START:
				moveUseful = 0;
				useMove = TM_FORWARD;
			break;
		}
	}
	// Actually perform the selected move
	switch (useMove)
	{
		case TM_ATTACK:
			// Make a piece attack a large stack
			// Useful if there is a large stack to jump on

			// Find a large stack that can be jumped on
			highest = -1; // reset
			for (int i = 0; i < (signed)possibleActiveMoves.size(); i++)
			{
				// Get numbers
				distance = GameData()->board.GetSizeOfStack(possibleActiveMoves.at(i)); //size of current stack
				potend = possibleActiveMoves.at(i) + distance;

				// Special case for left track
				if (possibleActiveMoves.at(i) <= 2 && potend > 2)
					potend += 3;

				if (GameData()->board.GetSizeOfStack(potend) >= highest)
				{
					highest = GameData()->board.GetSizeOfStack(potend);
					movepos = possibleActiveMoves.at(i);
				}
			}

			// Move piece
			GameData()->board.MovePiece(movepos, -1);

			if (highest < 2) // small stack -> not very useful
				moveUseful = 0;

		break;

		case TM_FORWARD:
			// Move a piece forward by the stack size
			// Useful if the lap was significant

			// Seek the farthest move ahead
			distance = -1; //reset

			for (int i = 0; i < (signed)possibleActiveMoves.size(); i++)
			{
				// Get numbers
				static int tempdist;
				tempdist = GameData()->board.GetSizeOfStack(possibleActiveMoves.at(i));

				// Can hit Lotus?
				if (i + tempdist == LOTUS_TRAMPOLINE)
					tempdist *= 2;

				if (tempdist >= distance)
				{
					distance = GameData()->board.GetSizeOfStack(possibleActiveMoves.at(i));
					movepos = possibleActiveMoves.at(i);
				}
			}

			// Move the piece
			if (distance < 3) // not particularly wortwhile
				moveUseful = 0;

			GameData()->board.MovePiece(movepos, -1);

		break;

		case TM_START:
			// Take out a piece from the start if possible
			// Otherwise perform a random action...
			// Useful if the start piece can jump on top of another stack
			// Not useful if a random move needed to be performed

			movepos = possibleStartMoves.at(0);

			// Decide on a path by taking the one with fewer pieces
			for (int i = 0; i < 7; i++)
			{
				if (i <= 2)
					path -= GameData()->board.GetSizeOfStack(i);
				else
					path += GameData()->board.GetSizeOfStack(i);
			}

			path *= -1; //flip it so you go down the path with fewer pieces

			// If there's only one stack left you must select from there
			if (possibleStartMoves.size() == 1)
			{
				movepos = possibleStartMoves.at(0);
			}
			// Go for the first stack that can jump on a piece (otherwise assume the above ^)
			for (int i = 0; i < possibleStartMoves.size(); i++)
			{
				static int tempend = -1;
				static PIECE temppc;

				if (path <= 0)
				{
					if (GameData()->board.GetSizeOfStack(possibleStartMoves.at(i)) == 4)
						tempend = 6;
					else
						tempend = GameData()->board.GetSizeOfStack(possibleStartMoves.at(i)) - 1;
				}
				else
					tempend = GameData()->board.GetSizeOfStack(possibleStartMoves.at(i)) + 2;

				temppc = GameData()->board.GetTopPiece(tempend);

				if (temppc != player.piece && temppc != PIECE_BAD)
				{
					moveid = i;
					movepos = possibleStartMoves.at(i);
					break;
				}
			}

			// Move the piece
			if (path <= 0) //left path
			{
				if (GameData()->board.GetSizeOfStack(possibleStartMoves.at(moveid)) == 4)
					endpos = 6;
				else
					endpos = GameData()->board.GetSizeOfStack(possibleStartMoves.at(moveid)) - 1;
=======
			int land = 2*(i - moves.at(i).beginpos);
			
			if(!(GameData()->board.IsPieceOnTop(player.piece, land)))
			{
				int select;
				srand((unsigned)time(0));
				select = rand()%moves.size()+1;
				GameData()->board.MovePiece(select, -1);
				return;
>>>>>>> 42a01e3772b1a6b7a2723a6804019a45ea0583c8
			}
			
			else
<<<<<<< HEAD
				endpos = GameData()->board.GetSizeOfStack(possibleStartMoves.at(moveid)) + 2;

			// Update and and change your state
			GameData()->board.MovePiece(movepos, endpos);
			//ableToMovePiece++;

		break;

		default:
			// Do nothing; your move was useless
			moveUseful = 0;
		break;
	}	
=======
			GameData()->board.MovePiece(moves.at(i).beginpos,land);
			return;
		}
	}

	
	
>>>>>>> 42a01e3772b1a6b7a2723a6804019a45ea0583c8
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
	//if i got attack!
	
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
	

	cout<<emotion<<endl;
	cout<<possibleActiveMoves.size()<<endl;
	cout<<ableToMovePiece<<endl;
	//cout<<typeid(this).name()<<endl;
	if (emotion > 1)
		this->stateMachine->setState(ST_ANGRY);

<<<<<<< HEAD
	//if(emotion > 1)
	//	this->stateMachine->setState(ST_VENGEFUL);
		//this->stateMachine->setState(ST_VENGEFUL);
	
=======
		this->stateMachine->setState(ST_VENGEFUL);
>>>>>>> 42a01e3772b1a6b7a2723a6804019a45ea0583c8
}
