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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> people(n), flats(m);
    for (int i = 0; i < n; i++)
    {
        cin >> people[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> flats[i];
    }
    sort(people.begin(), people.end());
    sort(flats.begin(), flats.end());
    int ans = 0;

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (people[i] - x <= flats[j] && flats[j] <= people[i] + x)
        {
            ans++;
            i++;
            j++;
        }
        else if (flats[j] > people[i] + x)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << ans;
    return 0;
}