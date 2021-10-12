#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
vector<vector<int>> tree(INF);
vector<bool> visited(INF, false);

int ans = 0;

bool dfs(int start, int pre)
{
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            if (!dfs(x, start) && !visited[start])
            {
                visited[x] = true;
                visited[start] = true;
                ans++;
            }
        }
    }
    return visited[start];
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
    visited.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    cout << ans;

    return 0;
}