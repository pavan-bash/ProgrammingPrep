#include <bits/stdc++.h>
using namespace std;
const int INF = 100;
vector<vector<int>> tree(INF);
vector<int> cnt(INF);
int n;

void dfs(int start, int pre)
{
    cnt[start] = 1;
    cout << start << " ";
    for (auto x : tree[start])
    {
        if (x != pre)
        {
            dfs(x, start);
            cnt[start] += cnt[x];
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    tree.resize(n + 2);
    cnt.resize(n + 2);
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

    cout << "\n";

    for (int i = 1; i < n + 2; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}