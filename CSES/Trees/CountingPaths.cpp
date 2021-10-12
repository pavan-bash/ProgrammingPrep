#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
vector<vector<int>> tree(INF), dp(2);
vector<int> height(INF), ans(INF);

void dfs(int start, int pre)
{
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            height[x] = height[start] + 1;
            dp[1][x] = start;
            dfs(x, start);
        }
    }
}

void dfs1(int start, int pre)
{
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            dfs1(x, start);
            ans[start] += ans[x];
        }
    }
}

int ancestor(int x, int k)
{
    int cnt = 1, y = x;
    while (k)
    {
        if (k & 1)
        {
            y = dp[cnt][y];
        }
        k = k / 2;
        cnt++;
    }
    return y;
}

int lowestCommonAncestor(int a, int b)
{
    if (a == 1 || b == 1)
    {
        return 1;
    }

    int x = height[a];
    int y = height[b];
    if (x > y)
    {
        a = ancestor(a, x - y);
    }
    else if (y > x)
    {
        b = ancestor(b, y - x);
    }

    if (a == b)
    {
        return a;
    }

    for (int i = dp.size() - 1; i > 0; i--)
    {
        if (dp[i][a] != dp[i][b])
        {
            a = dp[i][a];
            b = dp[i][b];
        }
    }

    return dp[1][a];
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
    dp[0].resize(n + 1);
    dp[1].resize(n + 1);
    height.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    int check, sz = 1;
    vector<int> temp(n + 1);

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

    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        int a = lowestCommonAncestor(x, y);

        ans[x] += 1;
        ans[y] += 1;
        ans[a] -= 1;

        int p = dp[1][a];
        if (p)
        {
            ans[p] -= 1;
        }
    }

    dfs1(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}