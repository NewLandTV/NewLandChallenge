#include "Util.h"

void Init()
{
	system("title NewLand Challenge");
	system("mode con cols=160 lines=40");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO consoleCursorInfo;

	consoleCursorInfo.bVisible = 0;
	consoleCursorInfo.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &consoleCursorInfo);
}

void gotoxy(int x, int y)
{
	COORD pos;

	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}