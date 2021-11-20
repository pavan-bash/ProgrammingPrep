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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), v(n + 2);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v[a[i]] = i;
    }
    v[n + 1] = n + 1;
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (v[i] < v[i - 1])
            ans++;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int vx = a[x], vy = a[y];
        if (abs(vx - vy) == 1)
        {
            if (vx > vy)
                swap(vx, vy);
            vector<int> before = {v[vx - 1], v[vx], v[vy], v[vy + 1]};
            swap(v[vx], v[vy]);
            vector<int> after = {v[vx - 1], v[vx], v[vy], v[vy + 1]};
            if (before[0] < before[1] && after[0] > after[1])
                ans++;
            if (before[0] > before[1] && after[0] < after[1])
                ans--;

            if (before[1] < before[2] && after[1] > after[2])
                ans++;
            if (before[1] > before[2] && after[1] < after[2])
                ans--;

            if (before[2] < before[3] && after[2] > after[3])
                ans++;
            if (before[2] > before[3] && after[2] < after[3])
                ans--;
        }
        else
        {
            vector<int> before_a = {v[vx - 1], v[vx], v[vx + 1]};
            vector<int> before_b = {v[vy - 1], v[vy], v[vy + 1]};
            swap(v[vx], v[vy]);
            vector<int> after_a = {v[vx - 1], v[vx], v[vx + 1]};
            vector<int> after_b = {v[vy - 1], v[vy], v[vy + 1]};

            if (before_a[0] < before_a[1] && after_a[0] > after_a[1])
                ans++;
            if (before_a[0] > before_a[1] && after_a[0] < after_a[1])
                ans--;
            if (before_a[1] < before_a[2] && after_a[1] > after_a[2])
                ans++;
            if (before_a[1] > before_a[2] && after_a[1] < after_a[2])
                ans--;

            if (before_b[0] < before_b[1] && after_b[0] > after_b[1])
                ans++;
            if (before_b[0] > before_b[1] && after_b[0] < after_b[1])
                ans--;
            if (before_b[1] < before_b[2] && after_b[1] > after_b[2])
                ans++;
            if (before_b[1] > before_b[2] && after_b[1] < after_b[2])
                ans--;
        }
        swap(a[x], a[y]);
        cout << ans << endl;
    }

    return 0;
}