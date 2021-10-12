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

vector<vector<pair<int, int>>> p = {{{1, 0}, {1, 1}, {1, 2}, {2, 0}}, {{1, -2}, {1, -1}, {1, 0}, {2, 0}}, {{1, 0}, {2, -1}, {2, 0}, {2, 1}}, {{0, 1}, {0, 2}, {1, 1}, {1, 2}}};

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}

void solve()
{
    vector<pair<int, int>> v;
    for (int i = 1; i <= 5; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);

    int x = v[0].first;
    int y = v[0].second;
    for (int j = 0; j < 4; j++)
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            int a = x + p[j][i].first;
            int b = y + p[j][i].second;
            if (a != v[i + 1].first || b != v[i + 1].second)
            {
                break;
            }
        }
        if (i == 4)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main()
{
    file_i_o();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}