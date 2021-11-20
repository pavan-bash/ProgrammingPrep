#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree, dp;
vector<int> dist;

void dfs(int root, int pre)
{
    for (auto node : tree[root])
    {
        if (node != pre)
        {
            dist[node] = dist[root] + 1;
            dfs(node, root);
        }
    }
}

int ancestor(int x, int k)
{
    int cnt = 1, y = x;
    while (k && cnt < dp.size())
    {
        if (k & 1)
        {
            y = dp[cnt][y];
        }
        k = k / 2;
        cnt++;
    }
    if (cnt == dp.size())
    {
        return 0;
    }
    return y;
}

int lca(int a, int b)
{
    if (a == 1 || b == 1)
    {
        return 1;
    }
    if (dist[a] > dist[b])
    {
        a = ancestor(a, dist[a] - dist[b]);
    }
    else if (dist[b] > dist[a])
    {
        b = ancestor(b, dist[b] - dist[a]);
    }
    if (a == b)
    {
        return a;
    }
    for (int i = dp.size() - 1; i >= 1; i--)
    {
        if (dp[i][a] != dp[i][b])
        {
            a = dp[i][a];
            b = dp[i][b];
        }
    }
    return dp[1][a];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nodes;
    cin >> nodes;

    vector<int> parent(nodes + 1);

    tree.resize(nodes + 1);
    dist.resize(nodes + 1);

    int edges = nodes - 1;
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        parent[y] = x;
    }
    dp.push_back(parent);
    dp.push_back(parent);

    dfs(1, 0);

    int check = 0, k = 1;

    do
    {
        check = 0;
        vector<int> lst;
        lst.push_back(0);
        for (int i = 1; i <= nodes; i++)
        {
            lst.push_back(dp[k][dp[k][i]]);
            check = check | dp[k][dp[k][i]];
        }
        k++;
        dp.push_back(lst);
    } while (check);

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
    return 0;
}