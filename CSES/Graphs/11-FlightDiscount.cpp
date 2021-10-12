#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
vector<pair<int, int>> parent;
int n, ans = LONG_LONG_MAX;

void dfs(int start, int pre, int w)
{
    if (visited[start])
        return;
    visited[start] = true;
    for (auto x : graph[start])
    {
        int node = x.first;
        if (node == n)
        {
            w += x.second;
            parent[node] = {start, x.second};
            pair<int, int> var = x;
            while (var.first != 1)
            {
                var = parent[var.first];
                ans = min(ans, w - var.second + var.second / 2);
            }
        }
        if (node != pre)
        {
            parent[node] = {start, x.second};
            dfs(node, start, w + x.second);
        }
    }
    visited[start] = false;
}

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
    int m;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    dfs(1, 0, 0);

    cout << ans;

    return 0;
}