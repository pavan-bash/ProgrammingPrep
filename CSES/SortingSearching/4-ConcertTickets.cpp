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
    int n, c;
    cin >> n >> c;
    vector<int> customers(c);
    multiset<int> tickets;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tickets.insert(x);
    }
    for (int i = 0; i < c; i++)
    {
        cin >> customers[i];
    }
    for (auto x : customers)
    {
        auto it = tickets.lower_bound(x + 1);
        if (it == tickets.begin())
        {
            cout << "-1\n";
        }
        else
        {
            it--;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
    return 0;
}