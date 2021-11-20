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
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    if (grid[0][0] == '.')
        dp[0][0] = 1;
    else
    {
        cout << "0";
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (grid[0][i] == '.')
        {
            dp[0][i] = 1;
        }
        else
            break;
    }
    for (int i = 1; i < n; i++)
    {
        if (grid[i][0] == '.')
        {
            dp[i][0] = 1;
        }
        else
            break;
    }
    int mod = 1e9 + 7;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}