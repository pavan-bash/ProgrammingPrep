#include <bits/stdc++.h>
using namespace std;

const int INF = 100;
vector<vector<int>> tree(INF);
vector<int> toleaf(INF);

int toLeaf(int node, int pre)
{
    int maxi = -1;
    if (tree[node].size() == 0)
    {
        return 0;
    }
    for (auto x : tree[node])
    {
        if (x != pre)
        {
            maxi = max(maxi, toLeaf(x, node));
        }
    }
    toleaf[node] = maxi + 1;
    return maxi + 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    tree.resize(n + 2);
    toleaf.resize(n + 2);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int ans = -1, m1 = -1, m2 = -2;
    int start;
    cin >> start;
    toLeaf(start, 0);
    if (tree[start].size() == 1)
    {
        ans = toleaf[tree[start][0]] + 1;
    }
    else
    {
        for (auto x : tree[start])
        {
            if (toleaf[x] > m2)
            {
                if (toleaf[x] > m1)
                {
                    m2 = m1;
                    m1 = toleaf[x];
                }
                else
                {
                    m2 = toleaf[x];
                }
            }
        }
        ans = m1 + m2 + 2;
    }

    // for (auto x : toleaf)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    cout << ans;

    return 0;
}