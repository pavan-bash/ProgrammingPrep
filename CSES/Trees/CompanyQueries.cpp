#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
vector<vector<int>> tree(INF), dp(1);

int ancestor(int x, int k)
{
    int cnt = 1, ans = x;
    while (k && cnt < dp.size())
    {
        if (k & 1)
        {
            ans = dp[cnt][ans];
        }
        k = k / 2;
        cnt++;
    }
    if (cnt >= dp.size())
        return -1;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    tree.resize(n + 1);
    vector<int> temp = {0, 0};
    dp[0].resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        tree[a].push_back(i);
        temp.push_back(a);
    }
    dp.push_back(temp);

    int check, sz = 1;

    do
    {
        check = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dp[sz][i] == 0)
            {
                temp[i] = 0;
            }
            else
            {
                temp[i] = dp[sz][dp[sz][i]];
                check = check | temp[i];
            }
        }
        dp.push_back(temp);
        sz++;
    } while (check);

    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 1; i <= q; i++)
    {
        int x, k;
        cin >> x >> k;
        int lol = ancestor(x, k);
        if (lol)
        {
            cout << lol;
        }
        else
        {
            cout << -1;
        }
        cout << "\n";
    }

    return 0;
}