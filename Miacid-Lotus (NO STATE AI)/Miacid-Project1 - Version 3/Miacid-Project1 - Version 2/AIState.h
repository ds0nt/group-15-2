#pragma once
class Player;
class AIState
{
public:
	

	virtual void onBoardChange() = 0;
	virtual void doTurn(Player p) = 0;
	//virtual void setEmotion();
	//virtual int getEmotion();
};