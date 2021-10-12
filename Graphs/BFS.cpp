#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> dist;
queue<int> q;

void bfs(int start)
{
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        cout << val << " ";
        for (auto x : graph[val])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
                dist[x] = dist[val] + 1;
            }
        }
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
    dist.resize(n + 1);
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
    bfs(start);

    cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}