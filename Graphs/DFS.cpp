#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node)
{
    if (visited[node])
    {
        return;
    }
    visited[node] = true;
    cout << node << " ";
    for (auto x : graph[node])
    {
        dfs(x);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, sz;
    cin >> n;
    graph.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> sz;
        graph[i].resize(sz);
        for (int j = 0; j < sz; j++)
        {
            cin >> graph[i][j];
        }
    }

    int start;
    cin >> start;
    dfs(start);

    return 0;
}