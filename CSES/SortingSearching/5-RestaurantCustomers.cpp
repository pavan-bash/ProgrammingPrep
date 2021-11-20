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
    set<pair<int, int>> times;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        times.insert({x, 0});
        times.insert({y, 1});
    }
    int ans = 0, best = 0;
    for (auto x : times)
    {
        if (x.second == 0)
        {
            ans++;
            best = max(best, ans);
        }
        else
        {
            ans--;
        }
    }
    cout << best;
    return 0;
}