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
	PlayerInfo* PlayerData = new PlayerInfo(); // 구조체 1개 생성


	//PlayerInfo* PlayerData = new PlayerInfo[10]; //구조체 배열 생성
	//구조체 배열 포인터로 접근
	//(*(PlayerData+1)).X = 1000;
	//(PlayerData + 1)->X = 1000;

	PlayerData->X = 5;
	PlayerData->Y = 5;
	PlayerData->Shape = "P";

	while (true)
	{
		cout << "====================================" << endl;
		GoToXY(PlayerData->X, PlayerData->Y);
		cout << PlayerData->Shape << endl;
		cout << "====================================" << endl;

		int Key = _getch();
		system("cls");

		if ((Key == 0x57 || Key == 0x77) && (PlayerData->Y > 0)) // w, W
		{
			PlayerData->Y -= 1;
		}
		else if ((Key == 0x41 || Key == 0x61) && (PlayerData->X > 0)) // a, A
		{
			PlayerData->X -= 1;
		}
		else if ((Key == 0x53 || Key == 0x73) && (PlayerData->Y < 100)) // s, S
		{
			PlayerData->Y += 1;
		}
		else if ((Key == 0x44 || Key == 0x64) && (PlayerData->X < 100)) // d, D
		{
			PlayerData->X += 1;
		}
		else if (Key == 13)
		{
			break;
		}
	}

	delete PlayerData;
	PlayerData = nullptr;

	return 0;
}