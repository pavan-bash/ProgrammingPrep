#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    vector<int> nums(n), dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    if (n == k)
    {
        cout << *max_element(nums.begin(), nums.end()) * n;
    }
    int maxi = 0;
    for (int i = 0; i < k; i++)
    {
        maxi = max(maxi, nums[i]);
        dp[i] = (i + 1) * maxi;
    }
    for (int i = k; i < n; i++)
    {
        int maxi = 0;
        for (int j = 0; j < k; j++)
        {
            maxi = max(maxi, nums[i - j]);
            dp[i] = max(dp[i], maxi * (j + 1) + dp[i - j - 1]);
        }
    }
    cout << dp[n - 1];

    return 0;
}