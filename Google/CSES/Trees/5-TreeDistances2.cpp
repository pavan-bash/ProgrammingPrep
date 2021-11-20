#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int nodes;
    cin >> nodes;
    vector<vector<int>> tree(nodes + 1, vector<int>(nodes + 1, LONG_LONG_MAX));

    for (int i = 1; i < nodes; i++)
    {
        tree[i].resize(nodes + 1);
        int x, y;
        cin >> x >> y;
        tree[x][y] = 1;
        tree[y][x] = 1;
        tree[i][i] = 0;
    }
    tree[nodes][nodes] = 0;

    for (int k = 1; k <= nodes; k++)
    {
        for (int i = 1; i <= nodes; i++)
        {
            for (int j = 1; j <= nodes; j++)
            {
                if (tree[i][k] != LONG_LONG_MAX && tree[k][j] != LONG_LONG_MAX)
                    tree[i][j] = min(tree[i][j], tree[i][k] + tree[k][j]);
            }
        }
    }

    for (int i = 1; i <= nodes; i++)
    {
        int ans = 0;
        for (int j = 1; j <= nodes; j++)
        {
            ans += tree[i][j];
        }
        cout << ans << " ";
    }
    return 0;
}