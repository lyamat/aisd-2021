#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, int *&visited, vector<vector<int>> &graph)
{
    visited[v] = 1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int to = graph[v].at(i);
        if (!visited[to])
        {
            dfs(to, visited, graph);
        }
    }
}

bool isConnected(int n, int *visited, vector<vector<int>> &graph)
{
    dfs(1,visited, graph);
    for (int i = 2; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    bool ans = false;
    vector<vector<int>> graph;

    cin >> n >> m;

    int visited[n];

    graph.resize(n+1);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ans = isConnected(n, visited, graph);

    if(ans) cout << m - n + 1;

   	else cout << -1;

    return 0;
}