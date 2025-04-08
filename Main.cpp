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
	int* NewArray = new int[20];

	for (int i = 0; i < 10; ++i)
	{
		*(NewArray + i) = *(DynamicArray + i);
		NewArray[i + 10] = (i + 1) * 4;
	}
	DynamicArray = NewArray;
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