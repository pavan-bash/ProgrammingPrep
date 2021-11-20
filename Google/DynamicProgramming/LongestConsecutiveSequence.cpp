#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_set<int> s(nums.begin(), nums.end());
    int ans = 0;

    for (auto x : nums)
    {
        if (s.find(x - 1) == s.end())
        {
            int curr = x;
            int lcl_ans = 1;

            while (s.find(curr + 1) != s.end())
            {
                lcl_ans++;
                curr++;
            }
            ans = max(ans, lcl_ans);
        }
    }
    cout << ans;

    return 0;
}