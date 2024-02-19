/*
 * - NewLand Challenge -
 * Made by JkhTV
 * Youtube : https://www.youtube.com/channel/UC0lR1aYGgOhFioC3IsazUtw
 */

#include "Main.h"
#include "Game.h"

int main(int argc, char** argv)
{
	MiniGameInit();

	// �Ϲ� ����
	if (argc == 1)
	{
		Init();

		while (1)
		{
			DrawTitle();

			int menuCode = DrawMenu();

			// ���� ����
			if (menuCode == 0)
			{
				int start = StartCountDown(DrawSelect());

				if (start == 1)
				{
					system("cls");
					gotoxy(CONSOLE_X_MAX / 2 - 7, CONSOLE_Y_MAX / 2 - 2);
					puts("���� ����!");
					Sleep(4000);
				}
			}
			// ���� ����
			else if (menuCode == 1)
			{
				DrawGameInfo();
			}
			// ����
			else if (menuCode == 2)
			{
				return 0;
			}

			system("cls");
		}
	}

	// �̴� ���� ���� �� �Ű����� ����
	if (strcmp(argv[1], "Start") == 0)
	{
		StartMiniGame(argv[2]);
	}
	else if (strcmp(argv[1], "List") == 0)
	{
		ShowMiniGames();
	}
	else
	{
		int i;

		printf("Not found command!\n>");

		for (i = 0; i < argc - 1; i++)
		{
			printf("%s ", argv[i + 1]);
		}
	}

	return 0;
}