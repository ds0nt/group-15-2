// Include the foundation
#include "foundation.h"

// Constructor
Board::Board()
{
	// Set the background to nothing then create piece locations
	this->background = NULL;
	this->CreateLocationsTable();
}

//Attempt to create the board with the specified number of players
bool Board::CreateBoard(int players)
{
	//Within the proper range?
	if (players < 2 || players > 4)
		return 0;

	this->numplayers = players;
	this->numstartstacks = 0;

	if (players == 2)
	{
		// Put pieces into the starting stacks
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4-i; j++)
				this->start[i].push_back(PIECE_P1);
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4-i; j++)
				this->start[4+i].push_back(PIECE_P2);
		}

		// Set the number of starting stacks
		this->numstartstacks = 8;
	}
	else if (players == 3)
	{
		// Put pieces into the starting stacks
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3-i; j++)
				this->start[i].push_back(PIECE_P1);
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3-i; j++)
				this->start[3+i].push_back(PIECE_P2);
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3-i; j++)
				this->start[6+i].push_back(PIECE_P3);
		}

		// Set the number of starting stacks
		this->numstartstacks = 9;
	}
	else if (players == 4)
	{
		// Put pieces into the starting stacks
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3-i; j++)
				this->start[i].push_back(PIECE_P1);
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3-i; j++)
				this->start[3+i].push_back(PIECE_P2);
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3-i; j++)
				this->start[6+i].push_back(PIECE_P3);
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3-i; j++)
				this->start[9+i].push_back(PIECE_P4);
		}

		// Set the number of starting stacks
		this->numstartstacks = 12;
	}

	// Create locations table for starting stacks
	this->CreateStartLocationsTable();

	return 1;
}

//Create the locations of each position on the board (the top left coordinate)
void Board::CreateLocationsTable()
{
	this->locations[0] = Point2f(118, 198);
	this->locations[1] = Point2f(118, 278);
	this->locations[2] = Point2f(164, 343);
	this->locations[3] = Point2f(360, 200);
	this->locations[4] = Point2f(360, 278);
	this->locations[5] = Point2f(314, 343);
	this->locations[6] = Point2f(239, 368);
	this->locations[7] = Point2f(239, 448);
	this->locations[8] = Point2f(117, 408);
	this->locations[9] = Point2f(41, 304);
	this->locations[10] = Point2f(41, 176);
	this->locations[11] = Point2f(117, 71);
	this->locations[12] = Point2f(239, 32);
	this->locations[13] = Point2f(359, 71);
	this->locations[14] = Point2f(437, 176);
	this->locations[15] = Point2f(437, 303);
	this->locations[16] = Point2f(361, 408);

	this->locations[17] = Point2f(300, 420); //finish zone
}

void Board::CreateStartLocationsTable()
{
	if (this->numplayers < 2 || this->numplayers  > 4)
		return;

	if (this->numplayers == 2)
	{
		this->slocations[0] = Point2f(215, 167);
		this->slocations[1] = Point2f(167, 215);
		this->slocations[2] = Point2f(167, 263);
		this->slocations[3] = Point2f(215, 311);

		this->slocations[4] = Point2f(263, 167);
		this->slocations[5] = Point2f(311, 215);
		this->slocations[6] = Point2f(311, 263);
		this->slocations[7] = Point2f(263, 311);

		this->slocations[8] = Point2f(0, 0);
		this->slocations[9] = Point2f(0, 0);
		this->slocations[10] = Point2f(0, 0);
		this->slocations[11] = Point2f(0, 0);
	}
	else if (this->numplayers == 3)
	{
		this->slocations[0] = Point2f(191, 191);
		this->slocations[1] = Point2f(191, 239);
		this->slocations[2] = Point2f(191, 287);

		this->slocations[3] = Point2f(239, 191);
		this->slocations[4] = Point2f(239, 239);
		this->slocations[5] = Point2f(239, 287);

		this->slocations[6] = Point2f(287, 191);
		this->slocations[7] = Point2f(287, 239);
		this->slocations[8] = Point2f(287, 287);

		this->slocations[9] = Point2f(0, 0);
		this->slocations[10] = Point2f(0, 0);
		this->slocations[11] = Point2f(0, 0);
	}
	else if (this->numplayers == 4)
	{
		this->slocations[0] = Point2f(215, 167);
		this->slocations[1] = Point2f(167, 215);
		this->slocations[2] = Point2f(167, 263);

		this->slocations[3] = Point2f(263, 167);
		this->slocations[4] = Point2f(311, 215);
		this->slocations[5] = Point2f(311, 263);

		this->slocations[6] = Point2f(215, 215);
		this->slocations[7] = Point2f(215, 263);
		this->slocations[8] = Point2f(215, 311);

		this->slocations[9] = Point2f(263, 215);
		this->slocations[10] = Point2f(263, 263);
		this->slocations[11] = Point2f(263, 311);
	}
}

//Set the background of the board
void Board::SetBackground(PNG * bg)
{
	this->background = bg;
}

//Set the Pieces on the board
void Board::SetPieces(PNG * unit_white, PNG * unit_black, PNG * unit_red, PNG * unit_blue)
{
	this->units[0] = unit_white;
	this->units[1] = unit_black;
	this->units[2] = unit_red;
	this->units[3] = unit_blue;
}

//Set the number on the pieces
void Board::SetNumbers(PNG img_num[24])
{
	for (int i = 0; i < 24; i++)
		this->numbers[i] = &img_num[i];
}

//NOTE: READ THIS!
//The range goes from -12 to 17. -12 -> -1 are starting stacks. 0 -> 16 are regular. 17 is the end zone.

//Return the top piece of any stack (starting, regular, finish zone)
PIECE Board::GetTopPiece(int pos)
{
	//Valid piece?
	if (pos < -this->numstartstacks || pos > MAX_GAME_POSITIONS)
		return PIECE_BAD; //invalid

	//Which type of stack?
	if (pos < 0)
	{
		//Starting stacks (flip the array)
		pos++; //-1 -> 0, -2 -> -1, ...
		pos *= -1; //0 -> 0, -1 -> 1, ...

		if (this->start[pos].empty())
			return PIECE_BAD;

		return this->start[pos].back();
	}

	//Finish stack (just for robustness of code)
	if (pos == MAX_GAME_POSITIONS)
	{
		if (this->finish.empty())
			return PIECE_BAD;

		return this->finish.back();
	}

	//Main board stacks
	if (this->position[pos].empty())
		return PIECE_BAD;

	return this->position[pos].back();
}

//Check if the top piece on a stack is the same as another piece
bool Board::IsPieceOnTop(PIECE player, int pos)
{
	if (player == PIECE_BAD)
		return 0; //though one could use the function for this purpose, it is intended for checking players...

	return (player == GetTopPiece(pos));
}

//Check if a spot on the map is empty (also works for starting stacks and finish zone)
bool Board::IsPosEmpty(int pos)
{
	return (PIECE_BAD == GetTopPiece(pos));
}

// Get the size of a stack
int Board::GetSizeOfStack(int pos)
{
	//Valid piece?
	if (pos < -this->numstartstacks || pos > MAX_GAME_POSITIONS)
		return 0; //invalid

	//Which type of stack?
	if (pos < 0)
	{
		//Starting stacks (flip the array)
		pos++; //-1 -> 0, -2 -> -1, ...
		pos *= -1; //0 -> 0, -1 -> 1, ...

		return (int) this->start[pos].size();
	}

	//Finish stack (just for robustness of code)
	if (pos >= MAX_GAME_POSITIONS)
		return (int) this->finish.size();

	//Main board stacks
	return (int) this->position[pos].size();
}

// Move a piece...


vector<move> Board::getPossibleMoves(PIECE player)
{
	vector<move> moves = vector<move>();

	for(int i = -MAX_START_STACKS; i < MAX_GAME_POSITIONS; i++)
	{
		if(this->GetTopPiece(i) == player)
		{
			if(i < 0)
			{
				int dist = this->GetSizeOfStack(i);
				if(dist < 4)
					moves.push_back(move(i, dist-1));
				moves.push_back(move(i, dist+2));
			}
			else
			{
				int dist = this->GetSizeOfStack(i);
				if(i < 3 && i + dist > 2)
					dist += 3;
				moves.push_back(move(i, i+dist));
			}
		}
	}

	return moves;
}


//Looks for the stacks with the players piece buried the deepest
//and returns the possible moves resulting
vector<move> Board::getDeepestPiecesMoves(PIECE player)
{
	int depth = 0;
	vector<int> deepSpots = vector<int>();

	for(int i = 0; i < MAX_GAME_POSITIONS; i++)
	{
		for(int j = 0; j < this->position[i].size(); j++)
		{
			if(this->position[i].at(j) == player)
			{
				int thisdepth = this->position[i].size() - j;
				if(thisdepth >= depth)
				{
					if(thisdepth > depth)
					{
						depth = thisdepth;
						deepSpots = vector<int>();
					}
					deepSpots.push_back(i);
				}
				break;
			}
		}
	}

	vector<move> moves = vector<move>();
	//we dont care about start pos
	for(int j = 0; j < deepSpots.size(); j++)
	{
		int i = deepSpots.at(j);
		int dist = this->GetSizeOfStack(i);
		if(i < 3 && i + dist > 2)
			dist += 3;
		moves.push_back(move(i, i+dist));
	}
	return moves;
}

bool Board::MovePiece(int begin, int end = -1)
{
	// Are the start and end points valid?
	if (begin < -this->numstartstacks || begin > MAX_GAME_POSITIONS || (end <= begin && end != -1))
	{
		GameData()->RecordMove(TM_NONE);
		return 0;
	}

	if (end < -1)
	{
		GameData()->RecordMove(TM_NONE);
		return 0;
	}

	// Come up with a possible end if we can
	if (begin >= 0 && end == -1)
	{
		end = begin + (int)this->position[begin].size();

		if (begin <= 2 && end > 2)
			end += 3;
	}

	// Fix up the range
	if (end > MAX_GAME_POSITIONS)
		end = MAX_GAME_POSITIONS;

	// Look at starting stacks
	if (begin < 0)
	{
		// Distance...
		int distance = end + 1; //index begins at 0

		// If we're on the second track, let's just say the distance is smaller
		if (end > 2)
			distance -= 3;

		// Get the proper array index
		int sbegin = begin;
		sbegin++;
		sbegin *= -1;

		if (this->start[sbegin].empty())
		{
			GameData()->RecordMove(TM_NONE);
			return 0;
		}

		// Is the size of the stack the same as the distance?
		if (this->start[sbegin].size() == (unsigned)distance)
		{
			// Size is okay. Perform the move.
			this->position[end].push_back(this->start[sbegin].back());
			this->start[sbegin].pop_back();

			// Append last move
			GameData()->RecordMove(TM_START);
			return 1;
		}

		// Assume failure
		GameData()->RecordMove(TM_NONE);
		return 0;
	}

	// Look at the two paths colliding into one (only the first path is necessary really...)
	if (begin <= 2)
	{
		// Cannot jump to second path
		if (end > 2 && end < 6)
		{
			GameData()->RecordMove(TM_NONE);
			return 0;
		}

		// Distance
		int distance = end - begin;

		// Let's say the distance is smaller when you converge onto the main path
		if (end > 2)
			distance -= 3;

		// Empty stack?
		if (this->position[begin].empty())
		{
			GameData()->RecordMove(TM_NONE);
			return 0;
		}

		// Is the size of the stack the same as the distance?
		if (this->position[begin].size() == (unsigned)distance)
		{
			if (end == LOTUS_TRAMPOLINE)
			{
				// Trampoline (double your distance)
				end += distance;

				if (end > MAX_GAME_POSITIONS)
					end = MAX_GAME_POSITIONS;

					
				if (end == MAX_GAME_POSITIONS)
					this->finish.push_back(this->position[begin].back());
				else
					this->position[end].push_back(this->position[begin].back());

				this->position[begin].pop_back();

				// Assume you did this just to move forward :|
				GameData()->RecordMove(TM_FORWARD);
				return 1;
			}

			// Size is okay. Perform the move.
			this->position[end].push_back(this->position[begin].back());
			this->position[begin].pop_back();

			// Check new stack size...
			if (this->position[end].size() > 2) //significant stack size?
				GameData()->RecordMove(TM_ATTACK); // assume you attacked
			else
				GameData()->RecordMove(TM_FORWARD); // otherwise assume it was to move forward

			return 1;
		}

		// Assume failure
		GameData()->RecordMove(TM_NONE);
		return 0;
	}

	// Regular movement
	if (begin > 2)
	{
		// Stack not empty?
		if (this->position[begin].empty())
		{
			GameData()->RecordMove(TM_NONE);
			return 0;
		}

		// Finish zone or regular?
		if (end == MAX_GAME_POSITIONS)
		{
			// Regular movement
			int distance = end - begin;

			// Is the size of the stack the same as the distance?
			if (this->position[begin].size() >= (unsigned)distance)
			{
				// Moving piece to the finish zone
				this->finish.push_back(this->position[begin].back());
				this->position[begin].pop_back();

				// You moved forward
				GameData()->RecordMove(TM_FORWARD);
				return 1;
			}

			// Assume failure
			GameData()->RecordMove(TM_NONE);
			return 0;
		}
		else
		{
			// Regular movement
			int distance = end - begin;

			// Is the size of the stack the same as the distance?
			if (this->position[begin].size() == (unsigned)distance)
			{
				// Did you select the trampoline spot?
				if (end == LOTUS_TRAMPOLINE)
				{
					// Trampoline (double your distance)
					end += distance;

					if (end > MAX_GAME_POSITIONS)
						end = MAX_GAME_POSITIONS;

					// Jump to the end?
					
					if (end == MAX_GAME_POSITIONS)
						this->finish.push_back(this->position[begin].back());
					else
						this->position[end].push_back(this->position[begin].back());

					this->position[begin].pop_back();

					// Assume you did this to move forward
					GameData()->RecordMove(TM_FORWARD);
					return 1;
				}
				else
				{
					// Normal movement
					this->position[end].push_back(this->position[begin].back());
					this->position[begin].pop_back();

					// Was this an attack?
					if (this->position[end].size() > 2) //significant stack size
						GameData()->RecordMove(TM_ATTACK);
					else
						GameData()->RecordMove(TM_FORWARD);

					return 1;
				}
			}

			// Assume failure
			GameData()->RecordMove(TM_NONE);
			return 0;
		}
	}

	// Assume failure
	GameData()->RecordMove(TM_NONE);
	return 0;
}

//Checks whether or not a given player may move at all
bool Board::PossibleMove(PIECE player)
{
	if (player == PIECE_BAD)
		return 0;

	for (int i = -MAX_START_STACKS; i < MAX_GAME_POSITIONS; i++)
	{
		if (this->IsPieceOnTop(player, i))
			return 1;
	}

	return 0;
}

//Check if a player has won the game (all their pieces in the end zone)
bool Board::PlayerHasWon(PIECE player)
{
	if (player == PIECE_BAD)
		return 0;

	return (this->PlayerPiecesRemaining(player) == 0);
}

//See how many pieces a player has remaining (useful for the AI purpose and seeing if someone has won)
int Board::PlayerPiecesRemaining(PIECE player)
{
	if (player == PIECE_BAD)
		return 0;

	//Solve this problem by figuring out the amount in the finish zone first
	int finished = 0;

	for (unsigned int i = 0; i < this->finish.size(); i++)
	{
		if (player == this->finish.at(i))
			finished++;
	}

	//Subtract the finished pieces from those you began with
	if (this->numplayers == 2)
		return PCS_PER_PLAYER_2 - finished;
	else if (this->numplayers == 3 || this->numplayers == 4)
		return PCS_PER_PLAYER_3OR4 - finished;

	return 0; //shouldn't happen
}

//See how many pieces remain in the active board (i.e. not finished)
int Board::BoardPiecesRemaining()
{
	if (this->numplayers == 2)
		return 2*PCS_PER_PLAYER_2 - (int)this->finish.size();
	else if (this->numplayers == 3 || this->numplayers == 4)
		return this->numplayers*PCS_PER_PLAYER_3OR4 - (int)this->finish.size();

	return 0; //assume the board is in error.
}

//Draw the board on the screen

void Board::RenderStack(std::vector<PIECE>* tile, Point2f location)
{
	int size = (int)tile->size();

	for (int j = 0; j < size; j++)
		this->units[tile->at(j)-1]->displayAt(location.x, location.y-j*5, 1);
	if (size > 1)
		this->numbers[size-1]->displayAt(location.x, location.y);
}
void Board::Render()
{
	//Mutex moving = new Mutex();
	//Draw the background
	this->background->displayAt(0,0);

	//Draw the starting position pieces
	for (int i = 0; i < this->numstartstacks; i++)
		this->RenderStack(&this->start[i], this->slocations[i]);

	//Draws regular board location pieces with numbers
	for (int i = 0; i < MAX_GAME_POSITIONS; i++)
		this->RenderStack(&this->position[i], this->locations[i]);
	// Draw finish zone
	this->RenderStack(&this->finish, this->locations[MAX_GAME_POSITIONS]);


	if (GameData()->selectedpos != -100) 
	{
		if(GameData()->selectedpos < 0)
		{
			GameData()->LotusSelect.displayAt(
				this->slocations[-GameData()->selectedpos-1].x, 
				this->slocations[-GameData()->selectedpos-1].y - this->GetSizeOfStack(GameData()->selectedpos) * 5+4, 
				1
			);
		}
		else if (GameData()->selectedpos >= 0)
		{			
			GameData()->LotusSelect.displayAt(
				this->locations[GameData()->selectedpos].x,
				this->locations[GameData()->selectedpos].y - this->GetSizeOfStack(GameData()->selectedpos) * 5+4,
				1
			);
		}
	}
}

// Attempt to return a location on the board given a click
bool Board::GetLocationFromXY(int x, int y, int &result)
{
	// Check starting locations
	for (int i = 0; i < this->numstartstacks; i++)
	{
		if (x >= this->slocations[i].x && x <= (this->slocations[i].x + this->units[0]->getWidth()) &&
			y >= this->slocations[i].y && y <= (this->slocations[i].y + this->units[0]->getHeight()))
		{
			result = -i - 1; //starting stacks are considered negative with respect to ids...
			return 1;
		}
	}

	// Check other locations
	for (int i = 0; i <= MAX_GAME_POSITIONS; i++)
	{
		if (x >= this->locations[i].x && x <= (this->locations[i].x + this->units[0]->getWidth()) &&
			y >= this->locations[i].y && y <= (this->locations[i].y + this->units[0]->getHeight()))
		{
			result = i;
			return 1;
		}
	}

	// Assume failure
	result = -100;
	return 0;
}

int Board::IsLocGood(int x1, int y1)
{
	for (int i = 0; i < 17; i++)
	{
		if (x1 > locations[i].x && x1 < (locations[i].x + 32) && y1 > locations[i].y && y1 < (locations[i].y + 32))
		{
			cout << "Good" << endl;
			return i;
		}
	}

	return 0; //uh... fix this...
}