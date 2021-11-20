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
    vector<int> coins(n);
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        sum += coins[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= coins[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - coins[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[n][i])
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}