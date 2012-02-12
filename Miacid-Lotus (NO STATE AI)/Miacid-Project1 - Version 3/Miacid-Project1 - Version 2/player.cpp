#include "player.h"

Player::Player()
{
	this->piece = PIECE_BAD;
	this->type = PT_HUMAN;
}

Player::~Player()
{

}


void Player::changeType()
{
	switch (this->type)
	{
	case PT_HUMAN:
		this->type = PT_RULEAI;
		break;
	case PT_RULEAI:
		this->type = PT_STATEAIHINT;
		break;
	case PT_STATEAIHINT:
		this->type = PT_STATEAI;
		break;
	case PT_STATEAI:
		this->type = PT_HUMAN;
		break;
	case PT_OFF:
		//DERP
		break;
	}
}

void Player::createStrategy()
{
	if (this->type == PT_STATEAI)
		this->strategy = new StateStrategy(this, ST_REGULAR);
	if (this->type == PT_STATEAIHINT)
	{
		this->strategy = new StateStrategy(this, ST_HINT_1);
	}
	else if (this->type == PT_RULEAI)
		this->strategy = new RuleStrategy();
}