#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
int n, q;
vector<long long> tree(INF);

long long rangeSum(int root, int x, int y, int start, int end)
{
    if (y < start || end < x)
    {
        return 0;
    }
    if (x <= start && end <= y)
    {
        return tree[root];
    }
    int mid = start + (end - start) / 2;
    return rangeSum(root * 2, x, y, start, mid) + rangeSum(root * 2 + 1, x, y, mid + 1, end);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x;
    cin >> x >> q;
    n = x * x;
    while (n & (n - 1))
    {
        n++;
    }
    tree.resize(2 * n);
    for (int i = 0; i < x * x; i++)
    {
        char c;
        cin >> c;
        if (c == '*')
            tree[n + i] = 1;
    }

    for (int i = n - 1; i > 0; i--)
    {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    tree[0] = tree[1];

    // for (auto x : tree)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    for (int i = 1; i <= q; i++)
    {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        a--;
        b--;
        s--;
        t--;
        cout << "a:" << a << " b:" << b << " s:" << s << " t:" << t << "\n";
        long long ans = 0;
        ans += rangeSum(1, 0, s * x + t, 0, n - 1);
        cout << ans << "\n";
        if (a != 0 && b != 0)
        {
            ans += rangeSum(1, 0, (a - 1) * x + b - 1, 0, n - 1);
            cout << ans << "\n";
            ans -= rangeSum(1, 0, s * x + b - 1, 0, n - 1);
            cout << ans << "\n";
            ans -= rangeSum(1, 0, s * (a - 1) + t, 0, n - 1);
            cout << ans << "\n";
        }
        else if (a == 0 && b != 0)
        {
            ans -= rangeSum(1, 0, s * x + b - 1, 0, n - 1);
        }
        else if (a != 0 && b == 0)
        {
            ans -= rangeSum(1, 0, s * (a - 1) + t, 0, n - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}