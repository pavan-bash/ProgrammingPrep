#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
vector<vector<int>> tree(INF);
vector<long long> value(INF), init(INF), man(INF);
vector<int> parent(INF);

long long dfs(int start, int pre)
{
    long long ans = 0;
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            parent[x] = start;
            ans += dfs(x, start);
        }
    }
    value[start] += ans;
    return value[start];
}

void dfs1(int start, int pre)
{
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            dfs1(x, start);
            man[start] += man[x];
        }
    }
    value[start] += man[start];
}

void update(int s, int x)
{
    if (init[s] == x)
    {
        return;
    }
    int diff = x - init[s];
    init[s] = x;
    man[s] += diff;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;

    tree.resize(n + 1);
    value.resize(n + 1);
    init.resize(n + 1);
    parent.resize(n + 1);
    man.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
        init[i] = value[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << value[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << parent[i] << " ";
    // }
    // cout << "\n";

    for (int i = 0; i < q; i++)
    {
        int type, s, x;
        cin >> type >> s;
        if (type == 1)
        {
            cin >> x;
            update(s, x);
        }
        else
        {
            dfs1(1, 0);
            fill(man.begin(), man.end(), 0);
            cout << value[s] << "\n";
        }
    }

    return 0;
}