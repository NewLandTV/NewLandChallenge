#ifndef __GAME_H__
#define __GAME_H__

#include "Main.h"

#define CONSOLE_X_MAX 160
#define CONSOLE_Y_MAX 40
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define ENTER 4

typedef struct _Game
{
	int id;
	char* name;
} Game;

void MiniGameInit();
void DrawTitle();
int DrawMenu();
void DrawGameInfo();
int DrawSelect();
int StartCountDown(int diffculty);
void NextMiniGame();
int GetKey();

#endif