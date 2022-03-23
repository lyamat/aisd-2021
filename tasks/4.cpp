#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int n, m;

bool checkOut(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

void setLen(vector<vector<int>> &graph, int i, int j)
{
    int way = graph[i][j];

    //graph[i-2][j+1];

    if (checkOut(i - 2, j + 1)) // 1
    {
        if (graph[i - 2][j + 1] > way + 1)
        {
            graph[i - 2][j + 1] = way + 1;
            setLen(graph, i - 2, j + 1);
        }
    }

    //graph[i-1][j+2];

    if (checkOut(i - 1, j + 2)) // 2
    {
        if (graph[i - 1][j + 2] > way + 1)
        {
            graph[i - 1][j + 2] = way + 1;
            setLen(graph, i - 1, j + 2);
        }
    }

    //graph[i+1][j+2];

    if (checkOut(i + 1, j + 2)) // 3
    {
        if (graph[i + 1][j + 2] > way + 1)
        {
            graph[i + 1][j + 2] = way + 1;
            setLen(graph, i + 1, j + 2);
        }
    }

    //graph[i+2][j+1];

    if (checkOut(i + 2, j + 1)) // 4
    {
        if (graph[i + 2][j + 1] > way + 1)
        {
            graph[i + 2][j + 1] = way + 1;
            setLen(graph, i + 2, j + 1);
        }
    }

    // graph[i+2][j-1];

    if (checkOut(i + 2, j - 1)) // 5
    {
        if (graph[i + 2][j - 1] > way + 1)
        {
            graph[i + 2][j - 1] = way + 1;
            setLen(graph, i + 2, j - 1);
        }
    }

    // graph[i+1][j-2];

    if (checkOut(i + 1, j - 2)) // 6
    {
        if (graph[i + 1][j - 2] > way + 1)
        {
            graph[i + 1][j - 2] = way + 1;
            setLen(graph, i + 1, j - 2);
        }
    }

    // graph[i-1][j-2];

    if (checkOut(i - 1, j - 2)) // 7
    {
        if (graph[i - 1][j - 2] > way + 1)
        {
            graph[i - 1][j - 2] = way + 1;
            setLen(graph, i - 1, j - 2);
        }
    }

    // graph[i-2][j-1];

    if (checkOut(i - 2, j - 1)) // 8
    {
        if (graph[i - 2][j - 1] > way + 1)
        {
            graph[i - 2][j - 1] = way + 1;
            setLen(graph, i - 2, j - 1);
        }
    }
}

int main()
{
    int i, j;

    cin >> n >> m;
    cin >> i >> j;

    graph.resize(n, vector<int>(m, 100000000));

    graph[0][0] = 0;

    setLen(graph, 0, 0);

    if(graph[i - 1][j - 1] == 100000000)
        cout << "NEVAR";

    else cout << graph[i - 1][j - 1];

    return 0;
}