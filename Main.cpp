#include <iostream>

using namespace std;

int main()
{
	int* DynamicArray = new int[10];
	
	for (int i = 0; i < 10; ++i)
	{
		DynamicArray[i] = (i + 1) * 3;
	}

	int* NewArray = new int[20];
	for (int i = 0; i < 20; ++i)
	{
		if (i < 10)
		{
			*(NewArray + i) = *(DynamicArray + i);
		}
		else
		{
			*(NewArray + i) = (i - 9) * 4;
		}
	}
	
	delete[] DynamicArray;

	DynamicArray = NewArray;

	for (int i = 0; i < 20; ++i)
	{
		cout << DynamicArray[i] << endl;
	}


	return 0;
}