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
    int n, sum, mod = 1e9 + 7;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        for (auto x : coins)
        {
            if (i >= x)
            {
                dp[i] = (dp[i] + dp[i - x]) % mod;
            }
        }
    }
    cout << dp[sum];
    return 0;
}