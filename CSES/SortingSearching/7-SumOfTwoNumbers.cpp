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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        v[i] = {y, i + 1};
    }
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (v[i].first + v[j].first == x)
        {
            cout << v[i].second << " " << v[j].second;
            return 0;
        }
        if (v[i].first + v[j].first < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}