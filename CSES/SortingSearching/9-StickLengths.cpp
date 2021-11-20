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

int32_t main()
{
    file_i_o();
    int n;
    cin >> n;
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }
    sort(lst.begin(), lst.end());
    int mid = (n - 1) / 2;
    int val = lst[mid];
    int ans = 0;
    for (auto x : lst)
    {
        ans += abs(x - val);
    }
    cout << ans;
    return 0;
}