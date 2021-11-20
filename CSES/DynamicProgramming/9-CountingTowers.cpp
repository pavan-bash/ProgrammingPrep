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
int mod = 1e9 + 7;

vector<pair<int, int>> dp(1e6 + 1);

void preprocess()
{
    dp[1].first = 1;
    dp[1].second = 1;
    for (int i = 2; i <= 1e6; i++)
    {
        dp[i].first = ((dp[i - 1].first * 4) % mod + dp[i - 1].second) % mod;
        dp[i].second = ((dp[i - 1].second * 2) % mod + dp[i - 1].first) % mod;
    }
}

int32_t main()
{
    file_i_o();
    int t;
    cin >> t;
    preprocess();
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n].first + dp[n].second) % mod << "\n";
    }
    return 0;
}