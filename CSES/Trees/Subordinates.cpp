#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6;
vector<vector<int>> tree(INF);
vector<int> ans(INF);

int dfs(int start)
{
    int r = 0;
    for (auto x : tree[start])
    {
        r += dfs(x) + 1;
    }
    ans[start] = r;
    return r;
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
    ans.resize(n + 1);

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        tree[x].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}