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


	//PlayerInfo* PlayerData = new PlayerInfo[10]; ����ü �迭 ����

	//(*(PlayerData+1)).X = 1000;	����ü �迭 �����ͷ� ����

	PlayerData->X = 5;
	PlayerData->Y = 5;
	PlayerData->Shape = "P";

	while (true)
	{
		cout << "====================================" << endl;
		GoToXY(PlayerData->X, PlayerData->Y);
		cout << PlayerData->Shape << endl;
		cout << "====================================" << endl;

		char c = _getch();
		system("cls");


		if (c == 'w' && (PlayerData->Y > 0))
		{
			PlayerData->Y -= 1;
		}
		else if (c == 'a' && (PlayerData->X > 0))
		{
			PlayerData->X -= 1;
		}
		else if (c == 's' && (PlayerData->Y < 100))
		{
			PlayerData->Y += 1;
		}
		else if (c == 'd' && (PlayerData->X < 100))
		{
			PlayerData->X += 1;
		}
		else if (c == 13)
		{
			break;
		}
	}

	delete[] PlayerData;
	PlayerData = nullptr;

	return 0;
}