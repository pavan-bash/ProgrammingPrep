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
    int n, m;
    cin >> n >> m;
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(m + 2));
    if (lst[0] != 0)
    {
        dp[0][lst[0]] = 1;
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (lst[i] != 0)
        {
            dp[i][lst[i]] = (dp[i - 1][lst[i] - 1] + dp[i - 1][lst[i]] + dp[i - 1][lst[i] + 1]) % mod;
            continue;
        }
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
        }
    }
    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum = (sum % mod + dp[n - 1][i] % mod) % mod;
    }
    cout << sum;
    return 0;
}