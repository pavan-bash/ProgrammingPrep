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
    int sum = 0, best = 0, neg = 0, maxi = LONG_LONG_MIN;
    for (auto x : lst)
    {
        maxi = max(maxi, x);
        if (x < 0)
        {
            neg++;
        }
        sum += x;
        best = max(best, sum);
        sum = max(0LL, sum);
    }
    if (n == neg)
    {
        cout << maxi;
    }
    else
        cout << best;
    return 0;
}