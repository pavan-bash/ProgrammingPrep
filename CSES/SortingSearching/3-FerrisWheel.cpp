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
    int n, w;
    cin >> n >> w;
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }
    sort(lst.begin(), lst.end());
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j)
    {
        if (lst[i] + lst[j] <= w)
        {
            i++;
        }
        j--;
        ans++;
    }
    if (i == j)
    {
        ans++;
    }
    cout << ans;
    return 0;
}