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
    int m;
    cin >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int n = m - 1;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0, j = i + gap; j < n; i++, j++)
        {
            int mini = INT_MAX;
            for (int k = i; k < j; k++)
            {
                mini = min(mini, dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1]);
            }
            dp[i][j] = mini;
        }
    }
    cout << dp[0][n - 1];
    return 0;
}