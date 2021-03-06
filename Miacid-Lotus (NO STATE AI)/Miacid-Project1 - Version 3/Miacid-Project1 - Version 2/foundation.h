#ifndef FOUNDATION_H
#define FOUNDATION_H

// This file is created so that .cpp files should only need to include this one header

// Common C++ and Windows
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <cmath>
#include <iostream>

// OpenGL
#pragma comment(lib, "glaux.lib")
#include "glut.h"
#include "GLAux.h"

// PicoPNG
#include "picopng.h"

// Game Data
#include "simple.h"
#include "rules.h"
#include "player.h"
#include "board.h"
#include "boardfunc.h"
#include "gamedata.h"
#include "boardCalc.h"


// Common Function Prototypes (to avoid plentiful .h files)
void GameSelectPlayerNum();
void GameSelectPlayers();
void GameMainBoard();
void GameResults();

void RenderLoading();
void RenderSelectPlayerNum();
void RenderSelectPlayers();
void RenderMainBoard();
void RenderResults();

void PerformHumanTurn(Player &player);

#endif // FOUNDATION_H