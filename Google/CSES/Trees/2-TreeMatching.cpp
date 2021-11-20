#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> visited;
int ans = 0;

void dfs(int root, int parent)
{
    for (auto node : tree[root])
    {
        if (node != parent)
            dfs(node, root);
    }
    if (parent && !visited[root] && !visited[parent])
    {
        ans++;
        visited[root] = visited[parent] = true;
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
    visited.resize(nodes + 1);

    for (int i = 0; i < nodes - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}