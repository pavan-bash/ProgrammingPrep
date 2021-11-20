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
    int n, x;
    cin >> n >> x;
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }
    map<int, int> m;
    if (n <= 2)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    m[lst[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (m.find(x - lst[i] - lst[j]) != m.end())
            {
                cout << i + 1 << " " << j + 1 << " " << m[x - lst[i] - lst[j]];
                return 0;
            }
        }
        m[lst[i]] = i + 1;
    }
    cout << "IMPOSSIBLE";
    return 0;
}