#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
int n, q;
vector<long long> tree(INF);

long long value(int k)
{
    long long ans = 0;
    do
    {
        ans += tree[k];
        k = k / 2;
    } while (k != 1);
    return ans;
}

void update(int root, int start, int end, int a, int b, int u)
{
    if (b < start || end < a)
    {
        return;
    }
    if (a <= start && end <= b)
    {
        tree[root] += u;
        return;
    }
    int mid = start + (end - start) / 2;
    update(root * 2, start, mid, a, b, u);
    update(root * 2 + 1, mid + 1, end, a, b, u);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x;
    cin >> x >> q;
    n = x;
    while (n & (n - 1))
    {
        n++;
    }
    tree.resize(2 * n);
    for (int i = 0; i < x; i++)
    {
        cin >> tree[n + i];
    }

    tree[0] = tree[1];

    for (auto x : tree)
    {
        cout << x << " ";
    }
    cout << "\n";

    for (int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            update(1, 0, n - 1, a - 1, b - 1, u);
            for (auto x : tree)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
        else
        {
            int k;
            cin >> k;
            cout << value(n + k - 1) << "\n";
        }
    }
    return 0;
}