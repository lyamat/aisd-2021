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

int num_of_components(int n, int *visited, vector<vector<int>> &graph)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans++;
            dfs(i, visited, graph);
        }
    }
    return ans;
}

int main()
{
    int n, m, ans = 0;
    int u, v;

    vector<vector<int>> graph;

    cin >> n >> m;

    int visited[n];

    graph.resize(n);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    ans = num_of_components(n, visited, graph);

   	cout << ans - 1;

    return 0;
}