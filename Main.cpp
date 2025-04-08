#include <iostream>

using namespace std;

int* DynamicArray = new int[10];

void Initialize()
{
	for (int i = 0; i < 10; ++i)
	{
		DynamicArray[i] = (i + 1) * 3;
	}
}

void ResizeDynamicArray()
{
	for (int i = 1; i < 11; ++i)
	{
		memset(DynamicArray, i, sizeof(int));
		*((DynamicArray + 9) + i) = i * 4;
	}

}

void PrintResult()
{
	if (DynamicArray != nullptr)
	{
		for (int i = 0; i < 20; ++i)
		{
			cout << DynamicArray[i] << endl;
		}
	}
	else
	{
		cout << "Dangling Pointer!" << endl;
	}
	
}


int main()
{
	Initialize();
	ResizeDynamicArray();
	PrintResult();

	return 0;
}