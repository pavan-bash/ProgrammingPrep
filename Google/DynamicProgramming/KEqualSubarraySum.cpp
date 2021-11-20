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

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int prefix = 0;
    int ans = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        prefix += nums[i];
        ans += m[prefix - k];
        m[prefix]++;
    }
    cout << ans;

    return 0;
}