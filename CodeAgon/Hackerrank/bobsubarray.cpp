#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
    int n, temp;
    cin >> n;
    ll ans = 0;
    vector<int> v(31);
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        for (int j = 0; j < 32; j++)
        {
            ll pof2 = 1 << j;
            if (temp & pof2)
            {
                ans += pof2 * i;
                v[j] = i;
            }
            else if (v[j])
            {
                ans += pof2 * v[j];
            }
        }
    }
    cout << ans;
    return 0;
}