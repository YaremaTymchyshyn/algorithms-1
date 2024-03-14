#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n)
{
    vector<float> bucket[100];

    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        bucket[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(bucket[i].begin(), bucket[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < bucket[i].size(); j++)
            arr[index++] = bucket[i][j];
    return;
}

int main()
{
    float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434, 0.892 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\tTEST 1\n";
    cout << "\tArray before sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    bucketSort(arr, n);
    cout << "\tArray after sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << endl;

    float arr2[] = { 0.345, 0.13, 0.9795, 0.234 };
    int f = sizeof(arr2) / sizeof(arr2[0]);
    cout << "\tTEST 2\n";
    cout << "\tArray before sorting: ";
    for (int i = 0; i < f; i++)
        cout << arr2[i] << " ";
    cout << endl;
    bucketSort(arr2, f);
    cout << "\tArray after sorting: ";
    for (int i = 0; i < f; i++)
        cout << arr2[i] << " ";
    cout << endl << endl;

    float arr3[] = { 0.231, 0.534, 0.4, 0.975, 0.1, 0.85, 0.4231 };
    int g = sizeof(arr3) / sizeof(arr3[0]);
    cout << "\tTEST 3\n";
    cout << "\tArray before sorting: ";
    for (int i = 0; i < g; i++)
        cout << arr3[i] << " ";
    cout << endl;
    bucketSort(arr3, g);
    cout << "\tArray after sorting: ";
    for (int i = 0; i < g; i++)
        cout << arr3[i] << " ";
    cout << endl << endl;

    return 0;
}