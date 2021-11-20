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
#define int long long
int32_t main()
{
    file_i_o();
    int n, t;
    cin >> n >> t;
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }
    sort(lst.begin(), lst.end());
    int maxi = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int j = t / lst[i];
        int mod = t % lst[i];
        if (mod >= (lst[i] + 1) / 2)
        {
            j++;
        }
        cnt += j;
        while (cnt > t)
        {
            j--;
            cnt--;
        }
        maxi = max(maxi, j * lst[i]);
    }
    cout << maxi;
    return 0;
}