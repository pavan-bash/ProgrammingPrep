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
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }
    vector<int> ans;
    for (auto num : lst)
    {
        if (ans.empty() || ans.back() < num)
        {
            ans.push_back(num);
        }
        else
        {
            auto it = lower_bound(ans.begin(), ans.end(), num);
            *it = num;
        }
    }
    cout << ans.size();
    return 0;
}