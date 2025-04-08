#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


struct PlayerInfo
{
	short X;
	short Y;
	string Shape;
};

void GoToXY(short X, short Y)
{
	COORD pos = { X, Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

int main()
{
	PlayerInfo* PlayerData = new PlayerInfo(); // ����ü 1�� ����
	PlayerData->X = 5;
	PlayerData->Y = 5;
	PlayerData->Shape = "P";

	while (true)
	{
		GoToXY(PlayerData->X, PlayerData->Y);
		cout << PlayerData->Shape << endl;

		char c = _getch();

		if (c == 'w')
		{
			PlayerData->Y -= 1;
		}
		else if (c == 'a')
		{
			PlayerData->X -= 1;
		}
		else if (c == 's')
		{
			PlayerData->Y += 1;
		}
		else if (c == 'd')
		{
			PlayerData->X += 1;
		}
		else
		{
			break;
		}

		system("cls");
	}

	delete PlayerData;
	PlayerData = nullptr;

	return 0;
}