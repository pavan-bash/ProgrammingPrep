#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;
int n, q;
vector<int> tree(200001, INF);

int rangeSum(int root, int x, int y, int start, int end)
{
    if (y < start || end < x)
    {
        return INF;
    }
    if (x <= start && end <= y)
    {
        return tree[root];
    }
    int mid = start + (end - start) / 2;
    return min(rangeSum(root * 2, x, y, start, mid), rangeSum(root * 2 + 1, x, y, mid + 1, end));
}

void update(int k, int u)
{
    tree[k] = min(tree[k * 2], tree[k * 2 + 1]);
    if (k == 1)
    {
        return;
    }
    update(k / 2, u);
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

    for (int i = n - 1; i > 0; i--)
    {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    tree[0] = tree[1];

    // for (auto x : tree)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    for (int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k, u;
            cin >> k >> u;
            tree[n + k - 1] = u;
            update((n + k - 1) / 2, u);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << rangeSum(1, x - 1, y - 1, 0, n - 1) << "\n";
        }
    }
    return 0;
}