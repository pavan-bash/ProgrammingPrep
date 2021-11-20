#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    file_i_o();
    int n, m;
    cin >> n >> m;

    int maxi = max(n, m);

    vector<vector<int>> dp(maxi + 1, vector<int>(maxi + 1));

    for (int i = 1; i <= maxi; i++)
    {
        dp[i][1] = i - 1;
        dp[1][i] = i - 1;
    }

    for (int i = 2; i <= maxi; i++)
    {
        for (int j = i + 1; j <= maxi; j++)
        {
            int ans = INT_MAX;
            for (int k = 1; k < i; k++)
            {
                ans = min(ans, dp[k][j] + dp[i - k][j]);
            }
            for (int k = 1; k < j; k++)
            {
                ans = min(ans, dp[i][k] + dp[i][j - k]);
            }
            ans++;
            dp[i][j] = dp[j][i] = ans;
        }
    }

    cout << dp[n][m];

    return 0;
}