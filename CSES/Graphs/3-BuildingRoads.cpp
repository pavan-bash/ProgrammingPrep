#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int start)
{
    if (visited[start])
    {
        return;
    }
    visited[start] = true;
    for (auto x : graph[start])
    {
        dfs(x);
    }
}

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    file_i_o();
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ans.push_back(i);
            dfs(i);
        }
    }

    int sz = ans.size();
    cout << sz - 1 << "\n";
    for (int i = 1; i < sz; i++)
    {
        cout << ans[i - 1] << " " << ans[i] << "\n";
    }
    return 0;
}