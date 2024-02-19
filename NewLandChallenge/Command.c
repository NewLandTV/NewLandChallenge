#include "Main.h"
#include "Game.h"

extern Game games[5];

void StartMiniGame(char* name)
{
	char path[64] = "C:\\NewLand\\NewLandChallenge\\";
	
	strcat_s(path, sizeof(path), name);
	strcat_s(path, sizeof(path), ".exe");
	puts(path);
	system(path);
}

void ShowMiniGames()
{
	int i;

	for (i = 0; i < 4; i++)
	{
		printf("%d. %s\n", games[i].id, games[i].name);
	}
}