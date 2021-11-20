#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree, dp;

int ancestor(int x, int k)
{
    int y = x, cnt = 1;
    while (k && cnt < dp.size())
    {
        if (k & 1)
        {
            y = dp[cnt][y];
        }
        k /= 2;
        cnt++;
    }
    if (cnt == dp.size())
    {
        return 0;
    }
    return y;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int nodes;
    cin >> nodes;
    tree.resize(nodes + 1);
    vector<int> parent(nodes + 1);
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

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        cout << ancestor(x, k) << "\n";
    }

    return 0;
}