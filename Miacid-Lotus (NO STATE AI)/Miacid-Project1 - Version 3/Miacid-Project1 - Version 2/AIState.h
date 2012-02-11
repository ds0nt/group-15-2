#pragma once
class Player;
class AIState
{
public:
	//int emotion;

	virtual void onBoardChange() = 0;
	virtual void doTurn(Player p) = 0;
	//virtual void setEmotion() = 0;
};