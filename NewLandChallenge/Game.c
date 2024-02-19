#include "Game.h"

int curMiniGame = 0;

Game games[5];

void MiniGameInit()
{
	// "E:\\Programming\Projects\\Game\\NewLandChallenge\\NewLandChallenge\\MiniGames.ncminigame"
	
	// Tetris
	games[0].id = 1;
	games[0].name = "Tetris";

	// Tic Tac Toe
	games[1].id = 2;
	games[1].name = "TicTacToe";

	// Snake
	games[2].id = 3;
	games[2].name = "Snake";

	// Minesweeper
	games[3].id = 4;
	games[3].name = "Minesweeper";

	// Avoid Shit
	games[4].id = 5;
	games[4].name = "AvoidShit";
}

void DrawTitle()
{
	int x = CONSOLE_X_MAX / 2 - 11;

	gotoxy(x, 7);
	printf("*--------------------*");
	gotoxy(x, 8);
	printf("|                    |");
	gotoxy(x, 9);
	printf("| NewLand Challenge! |");
	gotoxy(x, 10);
	printf("|                    |");
	gotoxy(x, 11);
	printf("*--------------------*");
}

int DrawMenu()
{
	int x = CONSOLE_X_MAX / 2 - 3;
	int y = CONSOLE_Y_MAX / 2 - 5;

	gotoxy(x - 6, y);
	printf("->  게임 시작");
	gotoxy(x - 2, y + 1);
	printf("게임 정보");
	gotoxy(x, y + 2);
	printf("종 료");

	while (1)
	{
		int inputKey = GetKey();

		switch (inputKey)
		{
		case UP:
			if (y > CONSOLE_Y_MAX / 2 - 5)
			{
				gotoxy(x - 6, y);
				printf("  ");
				gotoxy(x - 6, --y);
				printf("->");
			}
			break;
		case DOWN:
			if (y < CONSOLE_Y_MAX / 2 - 3)
			{
				gotoxy(x - 6, y);
				printf("  ");
				gotoxy(x - 6, ++y);
				printf("->");
			}
			break;
		case ENTER:
			Beep(470, 75);
			Beep(1200, 75);

			return y - CONSOLE_Y_MAX / 2 + 5;
		}
	}
}

void DrawGameInfo()
{
	int x = CONSOLE_X_MAX / 2 - 11;

	system("cls");
	gotoxy(x, 7);
	printf("*--------------------*");
	gotoxy(x, 8);
	printf("|        조작        |");
	gotoxy(x, 9);
	printf("|  이동 : W, A, S, D |");
	gotoxy(x, 10);
	printf("|  선택 : Enter      |");
	gotoxy(x, 11);
	printf("|  개발자 : JkhTV    |");
	gotoxy(x, 12);
	printf("*--------------------*");
	gotoxy(x - 7, CONSOLE_Y_MAX / 2 - 5);
	printf("->  Enter키를 눌러 메인 화면으로 돌아가기");

	while (1)
	{
		if (GetKey() == ENTER)
		{
			Beep(470, 75);
			Beep(1200, 75);

			break;
		}
	}
}

int DrawSelect()
{
	int x = CONSOLE_X_MAX / 2 - 11;
	int y = CONSOLE_Y_MAX / 2 - 5;

	system("cls");
	gotoxy(x, 7);
	printf("*--------------------*");
	gotoxy(x, 8);
	printf("|                    |");
	gotoxy(x, 9);
	printf("|     난이도 선택    |");
	gotoxy(x, 10);
	printf("|                    |");
	gotoxy(x, 11);
	printf("*--------------------*");

	x += 8;

	gotoxy(x - 5, 5);
	printf("게임 난이도 선택");
	gotoxy(x - 5, y);
	printf("->  보  통");
	gotoxy(x - 1, y + 1);
	printf("어려움");
	gotoxy(x - 1, y + 2);
	printf("뒤  로");

	while (1)
	{
		int inputKey = GetKey();

		switch (inputKey)
		{
		case UP:
			if (y > CONSOLE_Y_MAX / 2 - 5)
			{
				gotoxy(x - 5, y);
				printf("  ");
				gotoxy(x - 5, --y);
				printf("->");
			}
			break;
		case DOWN:
			if (y < CONSOLE_Y_MAX / 2 - 3)
			{
				gotoxy(x - 5, y);
				printf("  ");
				gotoxy(x - 5, ++y);
				printf("->");
			}
			break;
		case ENTER:
			Beep(470, 75);
			Beep(1200, 75);

			return y - CONSOLE_Y_MAX / 2 + 5;
		}
	}
}

int StartCountDown(int diffculty)
{
	int x = CONSOLE_X_MAX / 2;
	int y = CONSOLE_Y_MAX / 2 - 3;
	int timer;

	system("cls");

	gotoxy(x - 6, 2);

	if (diffculty == 0)
	{
		printf("보통 선택함");
	}
	else if (diffculty == 1)
	{
		printf("어려움 선택함");
	}
	else
	{
		return 0;
	}

	for (timer = 3; timer > 0; timer--)
	{
		gotoxy(x, y);
		printf("%d", timer);
		Sleep(1000);
	}

	NextMiniGame();

	return 1;
}

void NextMiniGame()
{
	if (curMiniGame < 4)
	{
		puts("\a");
		StartMiniGame(games[curMiniGame++].name);
		Sleep(500);
		NextMiniGame();
	}

	curMiniGame = 0;
}

int GetKey()
{
	char key = _getch();

	switch (key)
	{
	case 87:	// W
	case 119:	// w
		return UP;
	case 65:	// A
	case 97:	// a
		return LEFT;
	case 83:	// S
	case 115:	// s
		return DOWN;
	case 68:	// D
	case 100:	// d
		return RIGHT;
	case 13:	// Enter
		return ENTER;
	default:
		return -1;
	}
}