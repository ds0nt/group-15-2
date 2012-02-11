// Include the foundation
#include "foundation.h"
#include <cstring>


void GameSelectPlayers()
{
	// Create four players in memory, even though they may not be used
	for (int i = 0; i < 4; i++)
		GameData()->CreatePlayer();

	GameData()->players.at(0).piece = PIECE_P1;
	GameData()->players.at(1).piece = PIECE_P2;
	GameData()->players.at(2).piece = PIECE_P3;
	GameData()->players.at(3).piece = PIECE_P4;

	// Get number of players
	GameData()->numplayers = 0;
	GameData()->selectPlayerType = 0; // tell the rendering function what to do

	while (true)
	{
		// Reset click
		GameData()->ResetLastClick();
		Point2i mousepos;

		// Sit and wait for a click to come through
		do
		mousepos = GameData()->GetLastClick();
		while (mousepos == Point2i(-1,-1));

		if (mousepos.x >= 165 && mousepos.x <= 181 && mousepos.y >= 376 && mousepos.y <= 400)
			GameData()->numplayers = 2;
		else if (mousepos.x >= 244 && mousepos.x <= 260 && mousepos.y >= 376 && mousepos.y <= 400)
			GameData()->numplayers = 3;
		else if (mousepos.x >= 323 && mousepos.x <= 341 && mousepos.y >= 376 && mousepos.y <= 400)
			GameData()->numplayers = 4;

		// Acceptable value?
		if (GameData()->numplayers >= 2 && GameData()->numplayers <= 4)
		{
			if(GameData()->numplayers < 4)
				GameData()->players.at(3).type = PT_OFF;
			if(GameData()->numplayers < 3)
				GameData()->players.at(2).type = PT_OFF;
			
			break;
		}
	}

	GameData()->selectPlayerType = 1; // tell the rendering function what to do

	while (true)
	{
		// Reset click
		GameData()->ResetLastClick();
		Point2i mousepos;

		// Sit and wait for a click to come through
		do
		mousepos = GameData()->GetLastClick();
		while (mousepos == Point2i(-1,-1));

		// Adjust player types...
		if (mousepos.x >= 100 && mousepos.x <= 228 && mousepos.y >= 300 && mousepos.y <= 364)
			GameData()->players.at(0).changeType();
		else if (mousepos.x >= 300 && mousepos.x <= 428 && mousepos.y >= 300 && mousepos.y <= 364)
			GameData()->players.at(1).changeType();
		else if (mousepos.x >= 100 && mousepos.x <= 228 && mousepos.y >= 400 && mousepos.y <= 464 && GameData()->players.at(2).type != PT_OFF)
			GameData()->players.at(2).changeType();
		else if (mousepos.x >= 300 && mousepos.x <= 428 && mousepos.y >= 400 && mousepos.y <= 464 && GameData()->players.at(3).type != PT_OFF)
			GameData()->players.at(3).changeType();

		// Exit when you click on "Done"
		if (mousepos.x >= 232 && mousepos.x <= 296 && mousepos.y >= 350 && mousepos.y <= 414)
			break;
	}
	
	GameData()->players.at(0).createStrategy();
	GameData()->players.at(1).createStrategy();
	GameData()->players.at(2).createStrategy();
	GameData()->players.at(3).createStrategy();

	// Create the board
	GameData()->CreateBoard();

	// Change the scene to the game board
	GameData()->SceneState = SCENE_MAINBOARD;
}

void BoardChangeNotify()
{
	for (int i = 0; i < GameData()->GetNumPlayers(); i++)
	{
		Player* p = &(GameData()->players.at(i));

		if (GameData()->board.PlayerHasWon(p->piece))
			continue; //exit their turn

		if (p->type != PT_HUMAN)
			p->strategy->onBoardChange();
	}
}
// The main loop for the board game
void GameMainBoard()
{
	// The number of wins must be equal to the number of plays minus one to end
	static int numwins = 0;

	// Go through every player's turn until the game ends
	for (GameData()->currentPlayer = 0; GameData()->currentPlayer < GameData()->GetNumPlayers(); GameData()->currentPlayer++)
	{
		// If the player has won already then skip their turn
		Player* p = &(GameData()->players.at(GameData()->currentPlayer));

		if (GameData()->board.PlayerHasWon(p->piece))
			continue; //exit their turn

		// AI or Human?
		if (p->type == PT_HUMAN)
			PerformHumanTurn(*p);
		else
		{
			p->strategy->doTurn(*p);
		}

		// If the player just won the game, then let's exit...
		if (GameData()->board.PlayerHasWon(GameData()->players.at(GameData()->currentPlayer).piece))
			GameData()->SceneState = SCENE_RESULTS;
		BoardChangeNotify();
	}

	// End of game?
	/*if (numwins == GameData()->GetNumPlayers() - 1)
		GameData()->SceneState = SCENE_RESULTS;*/
}

// Show the results of the game
void GameResults()
{
	system("cls");
	printf("Congratulations! The game has been won!");

	// Press a key to end the game?
}