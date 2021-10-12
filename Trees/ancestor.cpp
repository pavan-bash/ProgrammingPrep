#include <bits/stdc++.h>
using namespace std;

const int INF = 100;
vector<vector<int>> tree(INF);
vector<vector<int>> dp(1);

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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    tree.resize(n + 2);
    vector<int> temp(n + 2);
    dp[0].resize(n + 2);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        temp[b] = a;
    }
    dp.push_back(temp);
    int sz = 1, check;
    do
    {
        check = 0;
        for (int i = 1; i <= n + 1; i++)
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
        for (int i = 1; i <= n + 1; i++)
        {
            cout << x[i] << " ";
        }
        cout << "\n";
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        cout << ancestor(x, k) << "\n";
    }
    return 0;
}