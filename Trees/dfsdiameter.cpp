#include <bits/stdc++.h>
using namespace std;

const int INF = 100;
vector<vector<int>> tree(INF);
vector<int> depth(INF);

void dfs(int start, int pre)
{
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            depth[x] = depth[start] + 1; // distance or depth
            dfs(x, start);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    tree.resize(n + 2);
    depth.resize(n + 2);
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

    int maxNode = -1, maxVal = -1;

    for (int i = 1; i <= n + 1; i++)
    {
        if (maxVal < depth[i])
        {
            maxVal = depth[i];
            maxNode = i;
        }
    }
    depth.clear();
    depth.resize(n + 2);
    dfs(maxNode, 0);
    int ans = -1;
    for (auto x : depth)
    {
        ans = max(ans, x);
    }
    cout << ans;
    return 0;
}