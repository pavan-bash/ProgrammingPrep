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
            // process root
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nodes;
    cin >> nodes;
    tree.resize(nodes + 1);
    dist.resize(nodes + 1);
    int edges = nodes - 1;
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1, 0);

    int a, maxi = -1;

    for (int i = 1; i <= nodes; i++)
    {
        if (maxi < dist[i])
        {
            maxi = dist[i];
            a = i;
        }
    }

    fill(dist.begin(), dist.end(), 0);
    dfs(a, 0);

    maxi = -1;
    for (int i = 1; i <= nodes; i++)
    {
        maxi = max(maxi, dist[i]);
    }

    cout << "diameter : " << maxi;

    return 0;
}