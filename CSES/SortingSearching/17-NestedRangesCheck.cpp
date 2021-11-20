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
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end());
    vector<int> a(n), b(n);
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] >= v[i - 1][0] && v[i][1] <= v[i - 1][1])
        {
            a[i - 1] = 1;
            b[i] = 1;
        }
    }
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << "\n";
    for (auto x : b)
    {
        cout << x << " ";
    }
    return 0;
}