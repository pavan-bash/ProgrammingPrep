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

    int a = max_element(dist.begin() + 1, dist.end()) - dist.begin();
    fill(dist.begin(), dist.end(), 0);
    dfs(a, 0);

    vector<int> dist1(dist.begin(), dist.end());

    int b = max_element(dist.begin() + 1, dist.end()) - dist.begin();
    fill(dist.begin(), dist.end(), 0);
    dfs(b, 0);

    for (int i = 1; i <= nodes; i++)
    {
        cout << max(dist[i], dist1[i]) << " ";
    }
    return 0;
}