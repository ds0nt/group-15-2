#pragma once
// Defines
#define PLAYERS_MAX 4

enum PIECE {PIECE_BAD, PIECE_P1, PIECE_P2, PIECE_P3, PIECE_P4};
enum PTYPE {PT_HUMAN, PT_RULEAI, PT_STATEAI, PT_STATEAIHINT, PT_OFF};
class Player;
// Includes
#include "foundation.h"
#include "AIStrategy.h"
#include "RuleStrategy.h"
#include "StateStrategy.h"
#include <vector>


class Player
{
public:
	// General
	PIECE piece;
	PTYPE type;
	AIStrategy* strategy;

	Player();
	~Player();
	void createStrategy();	
	void changeType();
};