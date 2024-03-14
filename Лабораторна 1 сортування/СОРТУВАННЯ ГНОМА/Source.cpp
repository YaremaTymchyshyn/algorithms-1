#include <iostream>
using namespace std;

void gnomesort(int f, int arr[])
{
	int index = 0;
	while (index < f)
	{
		if (index == 0 || arr[index] >= arr[index-1])
		{
			index++;
		}
		else
		{
			swap(arr[index], arr[index - 1]);
			index--;
		}
	}
	return;
}

int main()
{
	cout << "\tTEST 1" << endl;

	int arr[] = { 5,2,8,6,4,1,9,3,7,4 };
	int f = sizeof(arr) / sizeof(arr[0]);

	cout << "\tElements before sorting: ";
	for (int i = 0; i < f; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	gnomesort(f, arr);

	cout << "\tElements after sorting: ";
	for (int i = 0; i < f; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;



	cout << "\tTEST 2" << endl;

	int arr1[] = { 41,9,423,51,23,13,48,8,74 };
	int g = sizeof(arr1) / sizeof(arr1[0]);

	cout << "\tElements before sorting : ";
	for (int i = 0; i < g; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;

	gnomesort(g, arr1);

	cout << "\tElements after sorting: ";
	for (int i = 0; i < g; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl << endl;



	cout << "\tTEST 3" << endl;

	int arr2[] = { 65,345,23,1,87,6,3,45,8642,513,342,3 };
	int h = sizeof(arr2) / sizeof(arr2[0]);

	cout << "\tElements before sorting: ";
	for (int i = 0; i < h; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	gnomesort(h, arr2);

	cout << "\tElements after sorting: ";
	for (int i = 0; i < h; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl << endl;

	return 0;
}