#include <bits/stdc++.h>
using namespace std;

const int INF = 100;
vector<vector<int>> tree(INF);
vector<int> toleaf(INF);

int dfs(int start, int pre)
{
    int maxi = -1;
    if (tree[start].size() == 1)
    {
        return 0;
    }
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            maxi = max(maxi, dfs(x, start));
        }
    }
    toleaf[start] = maxi + 1;
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
    int start;
    cin >> start;
    dfs(start, 0);
    for (auto x : toleaf)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}