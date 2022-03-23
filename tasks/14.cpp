#include <iostream>
#include <vector>

using namespace std;

int n, m, module = 1e9 + 7;

#define ll long long

bool isEven(ll num)
{
    return num % 2 ? false : true;
}

vector<vector<ll>> mulGraphs(vector<vector<ll>> a, vector<vector<ll>> buff)
{
    vector<vector<ll>> c(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] = (c[i][j] + a[i][k] * buff[k][j] % module) % module;
            }
        }
    }
    return c;
}

vector<vector<ll>> binaryPowerOfGraphs(vector<vector<ll>> a, int power)
{
    vector<vector<ll>> buff(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i ++)
        buff[i][i] = 1;

    while (power)
        if (!isEven(power))
        {
            buff = mulGraphs(buff, a);
            power--;
        }
        else
        {
            a = mulGraphs(a, a);
            power /= 2;
        }

    return buff;
}

int main()
{
    cin >> n >> m;

    int u, v, power;
    cin >> u >> v >> power;

    vector<vector<ll>> graph(n, vector<ll>(n, 0));

    for (int i = 0; i < m; i++)
    {
        int a, buff;
        cin >> a >> buff;

        if (a == buff)
            graph[a - 1][buff - 1] += 2;
        else
        {
            graph[a - 1][buff - 1] += 1;
            graph[buff - 1][a - 1] += 1;
        }
    }

    graph = binaryPowerOfGraphs(graph, power);

    cout << graph[u - 1][v - 1];
}