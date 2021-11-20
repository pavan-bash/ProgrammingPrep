#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> v;
    vector<int> nl(n + 1), nr(n + 1), p(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        char y;
        cin >> x >> y;
        if (y == 'L')
        {
            v.push_back(x);
            nl[i + 1] = nl[i] + 1;
            nr[i + 1] = nr[i];
        }
        else
        {
            v.push_back(-x);
            nl[i + 1] = nl[i];
            nr[i + 1] = nr[i] + 1;
        }
    }

    int ans = 0, a = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + v[i - 1];

    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if ((nl[j] - nl[i]) == (nr[j] - nr[i]))
            {
                ans = max(ans, p[n] - (p[j] - p[i]));
                a = min(a, p[n] - (p[j] - p[i]));
            }
    ans = max(ans, abs(a));
    cout << ans;

    return 0;
}