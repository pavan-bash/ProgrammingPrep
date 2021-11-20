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

    int sum = n * (n + 1) / 2;

    if (sum & 1)
    {
        cout << "0";
        return 0;
    }

    sum = sum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    int mod = 1e9 + 7;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= i)
            {
                dp[i][j] = (dp[i - 1][j] % mod + dp[i - 1][j - i] % mod) % mod;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << (dp[n][sum] * 500000004) % mod;

    return 0;
}