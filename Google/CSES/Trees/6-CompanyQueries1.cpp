#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree, dp;

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
        return -1;
    }
    else if (y == 0)
    {
        return -1;
    }
    return y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int nodes, q;
    cin >> nodes >> q;

    tree.resize(nodes + 1);
    vector<int> parent(nodes + 1);

    for (int i = 2; i <= nodes; i++)
    {
        cin >> parent[i];
        tree[parent[i]].push_back(i);
    }

    dp.push_back(parent);
    dp.push_back(parent);

    int check = 0, k = 1;

    do
    {
        check = 0;
        vector<int> lst = {0};
        for (int i = 1; i <= nodes; i++)
        {
            lst.push_back(dp[k][dp[k][i]]);
            check = check | dp[k][dp[k][i]];
        }
        k++;
        dp.push_back(lst);
    } while (check);

    while (q--)
    {
        int x, k;
        cin >> x >> k;
        cout << ancestor(x, k) << "\n";
    }

    return 0;
}