#ifndef GAMEDATA_H
#define GAMEDATA_H

enum Scene {SCENE_DEFAULT, SCENE_SELECT_PLAYER_NUM, SCENE_SELECT_PLAYERS, SCENE_MAINBOARD, SCENE_RESULTS, SCENE_LOADING};

class GD
{
public:
	Board board;

	PNG LoadingImage;
	PNG LotusBoard;
	PNG LotusWhite;
	PNG LotusBlack;
	PNG LotusRed;
	PNG LotusBlue;
	PNG LotusNumbers[24];

	//
	PNG LotusTurn;
	PNG LotusWinner;
	PNG LotusFrontBoard;
	PNG LotusPlayers;
	PNG LotusPlayer1;
	PNG LotusPlayer2;
	PNG LotusPlayer3;
	PNG LotusPlayer4;
	PNG LotusAIRule;
	PNG LotusAIStateHint;
	PNG LotusAIState;
	PNG LotusHuman;
	PNG LotusFinished;
	PNG LotusNotPlaying;
	PNG LotusSelect;
	int selectedpos;
	//

	bool gLoaded;
	bool gRunning;
	bool bCreated;

	int numplayers;
	int currentPlayer;
	vector<Player> players;

	Scene SceneState;

	vector<TRule> Rules;
	vector<TMove> Moves;

private:
	Point2i lastclick;

public:
	GD();

	void CreateBoard();
	void SetBoardBackground(PNG * bg);
	void SetBoardPieces(PNG * unit_white, PNG * unit_black, PNG * unit_red, PNG * unit_blue);
	void SetBoardNumbers(PNG img_num[24]);
	
	void SetLastClick(int x, int y);
	Point2i GetLastClick();
	void ResetLastClick();

	void CreatePlayer();
	void NextPlayer();
	int GetNumPlayers();
	int randInt(int min, int max);

	void RecordMove(TMove move);
	void CreateRules();
};

// Return pointer to this class
GD * GameData();

#endif // GAMEDATA_H