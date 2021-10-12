#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e6;
vector<vector<int>> tree(INF);
vector<int> dist(INF), sz(INF), res(INF);
int n;

void dfs1(int start, int pre)
{
    res[start] = res[pre] - sz[start] - dist[start] + n - sz[start] + dist[start];

    for (int x : tree[start])
        if (x != pre)
            dfs1(x, start);
}

void dfs(int start, int pre)
{
    sz[start] = 1;
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            dfs(x, start);
            sz[start] += sz[x];
            dist[start] += dist[x] + sz[x];
        }
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    tree.resize(n + 1);
    dist.resize(n + 1);
    sz.resize(n + 1);
    res.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    res[1] = dist[1];

    for (auto x : tree[1])
    {
        dfs1(x, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}