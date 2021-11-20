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
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
        sum += lst[i];
    }
    sum = sum / k;
    int maxi = 0, lcl_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (lcl_sum + lst[i] <= sum)
        {
            lcl_sum += lst[i];
        }
        else
        {
            lcl_sum = lst[i];
        }
        maxi = max(maxi, lcl_sum);
    }
    return 0;
}