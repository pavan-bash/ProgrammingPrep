#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
vector<vector<int>> tree(INF), dp(1);
vector<int> height(INF);

void dfs(int start)
{
    for (auto x : tree[start])
    {
        height[x] = height[start] + 1;
        dfs(x);
    }
}

int ancestor(int x, int k)
{
    int cnt = 1, y = x;
    while (k && cnt < dp.size())
    {
        if (k & 1)
        {
            y = dp[cnt][y];
        }
        k = k / 2;
        cnt++;
    }
    if (cnt >= dp.size())
    {
        return 0;
    }
    return y;
}

int lowestCommonAncestor(int x, int y)
{
    if (x == 1 || y == 1)
    {
        return 1;
    }
    if (height[y] > height[x])
    {
        y = ancestor(y, height[y] - height[x]);
    }
    else if (height[x] > height[y])
    {
        x = ancestor(x, height[x] - height[y]);
    }

    if (x == y)
    {
        return x;
    }

    for (int i = dp.size() - 1; i > 0; i--)
    {
        if (dp[i][x] != dp[i][y])
        {
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[1][x];
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
    height.resize(n + 1);
    vector<int> temp = {0, 0};
    dp[0].resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        tree[a].push_back(i);
        temp.push_back(a);
    }
    dp.push_back(temp);

    int check, sz = 1;

    do
    {
        check = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dp[sz][i] == 0)
            {
                temp[i] = 0;
            }
            else
            {
                temp[i] = dp[sz][dp[sz][i]];
                check = check | temp[i];
            }
        }
        dp.push_back(temp);
        sz++;
    } while (check);

    height[1] = 1;
    dfs(1);

    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << lowestCommonAncestor(x, y) << "\n";
    }
    return 0;
}