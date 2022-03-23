#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long

struct node
{
    int next;
    ull weight = 100000000000000;
};
void setD(const vector<node> graph[], const int cur, ull *value)
{
    for (int j = 0; j < graph[cur].size(); j++)
    {
        int next = graph[cur][j].next;
        int weight = graph[cur][j].weight;
        if (value[cur] + weight < value[next])
            value[next] = value[cur] + weight;
    }
}

int main()
{
    int n, m;
    int begin, end;

    cin >> n >> m;

    vector<node> graph[n];

    ull value[n];

    for (int i = 0; i < n; i++)
        value[i] = 100000000000000;

    vector<bool> visited(n, false);

    node nd;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        nd.next = b;
        nd.weight = c;

        graph[a].push_back(nd);

        nd.next = a;
        graph[b].push_back(nd);
    }

    cin >> begin >> end;

    begin--;
    end--;

    value[begin] = 0;

    if (begin == end)
        cout << 0;

    else
    {
        for (int i = 0; i < n; i++)
        {
            ull v = -100000000000000;

            for (int j = 0; j < n; j++)
            {
                if (visited[j] == false)
                {
                    if (v == -100000000000000)
                        v = j;
                    else if (value[v] > value[j])
                        v = j;
                }
            }
            if (value[v] == 100000000000000)
                break;
            else
            {
                visited[v] = true;
                setD(graph, v, value);
            }
        }
        cout << value[end];
    }

    return 0;
}
