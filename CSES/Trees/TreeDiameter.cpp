#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
vector<vector<int>> tree(INF);
vector<int> dist(INF);

void dfs(int start, int pre)
{
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            dist[x] = dist[start] + 1;
            dfs(x, start);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    tree.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0);

    int maxNode = -1, maxDist = -1;

    for (int i = 1; i <= n; i++)
    {
        if (maxDist < dist[i])
        {
            maxDist = dist[i];
            maxNode = i;
        }
    }

    dist.clear();
    dist.resize(n + 1);
    dfs(maxNode, 0);

    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
    }

    cout << ans;

    return 0;
}