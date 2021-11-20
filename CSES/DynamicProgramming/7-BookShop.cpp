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
    int n, x;
    cin >> n >> x;
    vector<int> books(n), prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j >= books[i - 1])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - books[i - 1]] + prices[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][x];
    return 0;
}