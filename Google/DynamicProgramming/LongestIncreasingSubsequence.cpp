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
    vector<int> lst(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }

    vector<int> ans;

    for (auto x : lst)
    {
        if (ans.empty() || ans.back() < x)
        {
            ans.push_back(x);
        }
        else
        {
            auto it = lower_bound(ans.begin(), ans.end(), x);
            *it = x;
        }
    }

    cout << ans.size();

    return 0;
}