// Include the foundation
#include "foundation.h"
#include <cstring>

void GameSelectPlayerNum()
{
	// Reset click
	Point2i mousepos;
	GameData()->numplayers = 0;
	mousepos = GameData()->GetLastClick();
	if (mousepos.x >= 165 && mousepos.x <= 181 && mousepos.y >= 376 && mousepos.y <= 400)
		GameData()->numplayers = 2;
	else if (mousepos.x >= 244 && mousepos.x <= 260 && mousepos.y >= 376 && mousepos.y <= 400)
		GameData()->numplayers = 3;
	else if (mousepos.x >= 323 && mousepos.x <= 341 && mousepos.y >= 376 && mousepos.y <= 400)
		GameData()->numplayers = 4;

	// Acceptable value?
	if (GameData()->numplayers >= 2 && GameData()->numplayers <= 4)
	{
		for (int i = 0; i < 4; i++)
			GameData()->CreatePlayer();

		GameData()->players.at(0).piece = PIECE_P1;
		GameData()->players.at(1).piece = PIECE_P2;
		GameData()->players.at(2).piece = PIECE_P3;
		GameData()->players.at(3).piece = PIECE_P4;

		if(GameData()->numplayers < 4)
			GameData()->players.at(3).type = PT_OFF;
		if(GameData()->numplayers < 3)
			GameData()->players.at(2).type = PT_OFF;
		
		GameData()->SceneState = SCENE_SELECT_PLAYERS;
	}
	GameData()->ResetLastClick();
}

void GameSelectPlayers()
{
	// Reset click
	Point2i mousepos;

	mousepos = GameData()->GetLastClick();
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
	else if (mousepos.x >= 232 && mousepos.x <= 296 && mousepos.y >= 350 && mousepos.y <= 414)
	{
		GameData()->players.at(0).createStrategy();
		GameData()->players.at(1).createStrategy();
		GameData()->players.at(2).createStrategy();
		GameData()->players.at(3).createStrategy();

		// Create the board
		GameData()->CreateBoard();

		// Change the scene to the game board
		GameData()->SceneState = SCENE_MAINBOARD;

	}
	GameData()->ResetLastClick();
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
	Player* p = &(GameData()->players.at(GameData()->currentPlayer));

	if (GameData()->board.PlayerHasWon(p->piece))
	{
		GameData()->NextPlayer();
		return;
	}

	// AI or Human?
	if (p->type == PT_HUMAN)
		PerformHumanTurn(*p);
	else
	{
		Sleep(500);
		p->strategy->doTurn(*p);
		GameData()->NextPlayer();
		BoardChangeNotify();
	}

	if (GameData()->board.PlayerHasWon(p->piece))
		GameData()->SceneState = SCENE_RESULTS;
}

int position2 = -100;
void PerformHumanTurn(Player &player)
{
	bool allCovered = false;
	if (!GameData()->board.PossibleMove(player.piece))
	{
		allCovered = true;
	}
	
	Point2i mousepos = GameData()->GetLastClick();
	GameData()->ResetLastClick();
	if(GameData()->selectedpos == -100)
	{
		if (GameData()->board.GetLocationFromXY(mousepos.x, mousepos.y, GameData()->selectedpos))
		{
			printf("Clicked on Position %d\n", GameData()->selectedpos);
			PIECE testpiece = GameData()->board.GetTopPiece(GameData()->selectedpos);
			if (testpiece == PIECE_BAD)
				GameData()->selectedpos = -100;
			if (!allCovered)
				if(testpiece != player.piece)
					GameData()->selectedpos = -100;
		}
	}
	else if (position2 == -100)
	{
		if (GameData()->board.GetLocationFromXY(mousepos.x, mousepos.y, position2))
		{
			if(position2 == GameData()->selectedpos)
			{
				GameData()->selectedpos = -100;
				position2 = -100;
			}
		}
	}
	else
	{
		if (GameData()->board.MovePiece(GameData()->selectedpos, position2))
		{
			GameData()->NextPlayer();
			BoardChangeNotify();
		} 
		GameData()->selectedpos = -100;
		position2 = -100;
	}
}

void GameResults()
{
	system("cls");
	printf("Congratulations! The game has been won!");

	// Press a key to end the game?
}
