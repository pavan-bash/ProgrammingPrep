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

    int ans = 0, prefix = 0;
    vector<int> count(k);
    count[0] = 1;
    for (int i = 0; i < n; i++)
    {
        prefix = (prefix + nums[i] % k + k) % k;
        ans += count[prefix];
        count[prefix]++;
    }
    cout << ans;

    return 0;
}