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
    int n, ans = 0;
    cin >> n;
    while (n)
    {
        string s = to_string(n);
        n -= *max_element(s.begin(), s.end()) - 48;
        ans++;
    }
    cout << ans;
    return 0;
}