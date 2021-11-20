#include <bits/stdc++.h>
using namespace std;

#define int long long

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    file_i_o();
    int n;
    cin >> n;

    vector<int> lst(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }

    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = {lst[i], 0};
    }

    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0, j = i + gap; j < n; i++, j++)
        {
            int x1 = lst[j] + dp[i][j - 1].second;
            int x2 = lst[i] + dp[i + 1][j].second;
            if (x1 >= x2)
            {
                dp[i][j] = {x1, dp[i][j - 1].first};
            }
            else
            {
                dp[i][j] = {x2, dp[i + 1][j].first};
            }
        }
    }

    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //     {
    //         cout << "[" << y.first << "," << y.second << "] ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[0][n - 1].first;

    return 0;
}