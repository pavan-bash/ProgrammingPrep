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
    int x, n;
    cin >> x >> n;
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }
    set<pair<int, int>> s;
    map<int, int> m;
    s.insert({1, x});
    m[x] = 1;
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound({lst[i], 0});
        if (it->first != lst[i])
        {
            it--;
        }
        pair<int, int> p = *it;
        int val = p.second - p.first + 1;
        m[val]--;
        if (!m[val])
            m.erase(val);
        s.erase(it);
        s.insert({p.first, lst[i]});
        m[lst[i] - p.first + 1]++;
        s.insert({lst[i] + 1, p.second});
        m[p.second - lst[i]]++;
        cout << m.rbegin()->first << " ";
    }
    return 0;
}