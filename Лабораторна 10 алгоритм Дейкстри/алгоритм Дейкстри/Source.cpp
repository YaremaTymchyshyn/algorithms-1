#include <iostream>
#include <limits.h>
using namespace std;

#define vertex 6 // кількість вершин

int minDistance(int path[], bool shortpath[])
{
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertex; v++)
        if (shortpath[v] == false && path[v] <= min)
            min = path[v], minIndex = v;

    return minIndex;
}

void print(int path[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < vertex; i++)
    {
        cout << i << "\t\t" << path[i] << endl;
    }
}

int* dijkstra(int graph[vertex][vertex], int source)
{
    int* path = new int[vertex];
    bool* shortpath = new bool[vertex];

    for (int i = 0; i < vertex; i++)
    {
        path[i] = INT_MAX, shortpath[i] = false;
    }

    path[source] = 0;

    for (int count = 0; count < vertex - 1; count++)
    {
        int j = minDistance(path, shortpath);
        shortpath[j] = true;

        for (int i = 0; i < vertex; i++)
        {
            if (!shortpath[i] && graph[j][i] && path[j] != INT_MAX 
                && path[j] + graph[j][i] < path[i])
            {
                path[i] = path[j] + graph[j][i];
            }
        }
    }

    print(path);
    return path;
}

bool Test1()
{
    int graph[vertex][vertex] = { { 0, 7, 9, 0, 0, 14 },
                                  { 7, 0, 10, 15, 0, 0, },
                                  { 9, 10, 0, 11, 0, 2 },
                                  { 0, 15, 11, 0, 6, 0 },
                                  { 0, 0, 0, 6, 0, 9 },
                                  { 14, 0, 2, 0, 9, 0 } };


    int* result = dijkstra(graph, 0);

    return result[0] == 0 && result[1] == 7 && result[2] == 9 && result[3] == 20 && result[4] == 20 && result[5] == 11;
}

int main()
{

    cout << "Test1 : " << (Test1() ? "passed\n" : "falled\n") << endl;

    return 0;
}