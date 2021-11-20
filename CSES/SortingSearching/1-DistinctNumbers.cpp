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
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }
    sort(lst.begin(), lst.end());
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (lst[i] != lst[i - 1])
            ans++;
    }
    cout << ans;
    return 0;
}