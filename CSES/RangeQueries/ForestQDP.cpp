#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<vector<char>> grid(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = dp[1][i - 1];
        if (grid[1][i] == '*')
            dp[1][i]++;

        dp[i][1] = dp[i - 1][1];
        if (grid[i][1] == '*')
        {
            dp[i][1]++;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            if (grid[i][j] == '*')
            {
                dp[i][j]++;
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        int ans = dp[x][y] - dp[x][b - 1] - dp[a - 1][y] + dp[a - 1][b - 1];
        cout << ans << "\n";
    }
    return 0;
}