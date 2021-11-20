#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> ans;

void dfs(int root)
{
    ans[root] = 1;
    for (auto node : tree[root])
    {
        dfs(node);
        ans[root] += ans[node];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int nodes;
    cin >> nodes;
    tree.resize(nodes + 1);
    ans.resize(nodes + 1);

    for (int i = 2; i <= nodes; i++)
    {
        int x;
        cin >> x;
        tree[x].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= nodes; i++)
    {
        cout << ans[i] - 1 << " ";
    }

    return 0;
}