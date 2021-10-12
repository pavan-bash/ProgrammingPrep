#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<pair<int, int>>> graph;
vector<bool> visited, processed;
int n;

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

bool dfs(int start, int val)
{
    bool ans = false;
    for (auto x : graph[start])
    {
        int node = x.first;
        if (node == val)
        {
            return true;
        }
        if (!visited[node])
        {
            visited[node] = true;
            ans = ans || dfs(node, val);
        }
    }
    return ans;
}

int32_t main()
{
    file_i_o();
    int m;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1);
    processed.resize(n + 1);
    vector<tuple<int, int, int>> edges;
    vector<int> dist(n + 1, -1e12);

    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
        graph[a].push_back({b, w});
    }

    dist[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = max(dist[b], dist[a] + w);
        }
    }

    for (auto e : edges)
    {
        int a, b, w;
        tie(a, b, w) = e;
        if (dist[b] < dist[a] + w)
        {
            if (dfs(b, n))
            {
                fill(visited.begin(), visited.end(), false);
                if (dfs(1, b))
                {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
    cout << dist[n] << "\n";

    return 0;
}