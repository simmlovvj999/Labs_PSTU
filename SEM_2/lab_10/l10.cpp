#include <iostream>
using namespace std;

int main()
{
	//lab 10 var 13
	srand(time(0));
	int rows = 3;
	int cols = 4;

	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10 + 1;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int z;
	cin >> z;

	bool* todelete = new bool[cols];
	for (int j = 0; j < cols; j++)
	{
		todelete[j] = false;
	}

	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			if (arr[i][j] == z)
			{
				todelete[j] = true;
				break;
			}
		}	
	}

	int sc = 0;
	for (int j = 0; j < cols; j++)
	{
		if (!todelete[j])
		{
			sc++;
		}
	}

    int** tmp = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		tmp[i] = new int[sc];
	}

	int v = 0;
	for (int j = 0; j < cols; j++)
	{
		if (!todelete[j])
		{
			for (int i = 0; i < rows; i++)
			{
				tmp[i][v] = arr[i][j];
			}
			v++;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < sc; j++)
		{
			cout << tmp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	for (int i = 0; i < rows; i++)
	{
		delete[] tmp[i];
	}
	delete[] tmp;
	delete[] todelete;

	return 0;
}
