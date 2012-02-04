#include "foundation.h"

// Display a "Loading..." message on the screen
void RenderLoading()
{
	static PNG* pngLoading = &(GameData()->LoadingImage);
	pngLoading->displayAt(glutGet(GLUT_WINDOW_WIDTH) - pngLoading->getWidth(), glutGet(GLUT_WINDOW_HEIGHT) - pngLoading->getHeight(), 1);
}

// The screen displayed to select the number of players
void RenderSelectPlayer(PTYPE p, int x, int y)
{
	switch (p)
	{
	case PT_HUMAN:
		GameData()->LotusHuman.displayAt(x,y);
		break;
	case PT_RULEAI:
		GameData()->LotusAIRule.displayAt(x,y);
		break;
	case PT_STATEAI:
		GameData()->LotusAIState.displayAt(x,y);
		break;
	}
}

void RenderSelectPlayers()
{
	GameData()->LotusFrontBoard.displayAt(0, 0);
	if (!GameData()->selectPlayerType)
		GameData()->LotusPlayers.displayAt(0, 300);
	else
	{
		GameData()->LotusPlayer1.displayAt(100, 300);
		RenderSelectPlayer(GameData()->players.at(0).type, 100, 325);
		GameData()->LotusPlayer2.displayAt(300, 300);
		RenderSelectPlayer(GameData()->players.at(1).type, 300, 325);
		GameData()->LotusPlayer3.displayAt(100, 400);
		RenderSelectPlayer(GameData()->players.at(2).type, 100, 425);
		GameData()->LotusPlayer4.displayAt(300, 400);
		RenderSelectPlayer(GameData()->players.at(3).type, 300, 425);
		GameData()->LotusFinished.displayAt(232, 350);
	}
}

// The main render function (can be used to call other rendering functions)
void RenderMainBoard()
{
	// Render the board
	GameData()->board.Render();

	// Render player scores?
}

// Shown when the game has been finished. Who won?
void RenderResults()
{
	GameData()->LotusBoard.displayAt(0, 0);
}