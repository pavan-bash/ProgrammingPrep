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
    if (n == 1)
    {
        cout << "1";
        return 0;
    }
    int i = 0, j = 0;
    set<int> s;
    int ans = 0;
    while (i < n && j < n)
    {
        while (j < n && s.find(lst[j]) == s.end())
        {
            s.insert(lst[j]);
            ans = max(ans, j - i + 1);
            j++;
        }
        while (j < n && s.find(lst[j]) != s.end())
        {
            s.erase(lst[i]);
            i++;
        }
    }
    cout << ans;
    return 0;
}