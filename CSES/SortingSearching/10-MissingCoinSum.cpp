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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (ans < v[i])
        {
            break;
        }
        else
        {
            ans += v[i];
        }
    }
    cout << ans;
    return 0;
}