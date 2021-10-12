#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6;
vector<vector<int>> tree(INF), dp(2);
vector<int> height(INF);

void dfs(int start, int pre)
{
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            dp[1][x] = start;
            height[x] = height[start] + 1;
            dfs(x, start);
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

int dist(int a, int b)
{
    // cout << a << " " << b << "\n";
    if (a == 1)
    {
        return height[b];
    }
    else if (b == 1)
    {
        return height[a];
    }
    int x = height[a];
    int y = height[b];
    int ans = abs(x - y);
    if (x > y)
    {
        a = ancestor(a, ans);
    }
    else if (y > x)
    {
        b = ancestor(b, ans);
    }

    if (a == b)
    {
        return ans;
    }

    for (int i = dp.size() - 1; i > 0; i--)
    {
        if (dp[i][a] != dp[i][b])
        {
            a = dp[i][a];
            b = dp[i][b];
            ans += 2 * pow(2, i - 1);
        }
    }
    ans += 2;
    return ans;
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

    for (auto x : dp)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        cout << height[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << dist(a, b) << "\n";
    }
    return 0;
}