#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> dist;

void dfs(int root, int parent)
{
    for (auto node : tree[root])
    {
        if (node != parent)
        {
            dist[node] = dist[root] + 1;
            dfs(node, root);
        }
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
    dist.resize(nodes + 1);

    for (int i = 0; i < nodes - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1, 0);
    int maxi = -1, idx;

    for (int i = 1; i <= nodes; i++)
    {
        if (maxi < dist[i])
        {
            maxi = dist[i];
            idx = i;
        }
    }
    fill(dist.begin(), dist.end(), 0);
    dfs(idx, 0);
    cout << *max_element(dist.begin() + 1, dist.end());
    return 0;
}