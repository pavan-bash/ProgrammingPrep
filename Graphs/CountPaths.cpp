#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited, res, paths;
queue<int> q;

void topologicalSort(int start)
{
    if (visited[start] != 0)
        return;
    visited[start] = 1;

    for (auto x : graph[start])
    {
        topologicalSort(x);
    }

    for (auto x : graph[start])
    {
        if (visited[x] != 2)
        {
            return;
        }
    }
    res.push_back(start);
    visited[start] = 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, e;
    cin >> n >> e;
    graph.resize(n + 1);
    visited.resize(n + 1);
    paths.resize(n + 1);
    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = n; i >= 1; i--)
    {
        if (!visited[i])
            topologicalSort(i);
    }
    res.push_back(-1);
    reverse(res.begin(), res.end());
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }

    int start, end;
    cin >> start >> end;

    paths[start] = 1;
    int s;
    for (s = 1; s <= n; s++)
    {
        if (res[s] == start || res[s] == end)
        {
            break;
        }
    }

    for (int j = s; res[j] != end; j++)
    {
        for (auto x : graph[res[j]])
        {
            paths[x] += paths[res[j]];
        }
    }

    cout << "\n"
         << paths[end];

    return 0;
}