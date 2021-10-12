#include <bits/stdc++.h>
using namespace std;

#define int long long

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    file_i_o();
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<bool> visited(n + 1);
    priority_queue<pair<int, int>> q;
    vector<int> dist(n + 1, LONG_LONG_MAX);

    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    dist[1] = 0;
    q.push({0, 1});

    while (!q.empty())
    {
        int node = q.top().second;
        q.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        for (auto x : graph[node])
        {
            int a = x.first;
            int b = x.second;
            if (dist[a] > dist[node] + b)
            {
                dist[a] = dist[node] + b;
                q.push({-dist[a], a});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}