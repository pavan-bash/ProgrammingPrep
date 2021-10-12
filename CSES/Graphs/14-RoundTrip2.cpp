#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited, processed;
vector<int> parent;

void dfs(int start)
{
    visited[start] = true;
    processed[start] = true;
    for (auto x : graph[start])
    {
        if (!processed[x])
        {
            parent[x] = start;
            dfs(x);
        }
        else
        {
            vector<int> ans = {x};
            do
            {
                ans.push_back(start);
                start = parent[start];
            } while (start != x);
            ans.push_back(ans[0]);

            reverse(ans.begin(), ans.end());

            cout << ans.size() << "\n";
            for (auto y : ans)
            {
                cout << y << " ";
            }
            exit(0);
        }
    }
    processed[start] = 0;
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
    parent.resize(n + 1);
    processed.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
        if (!visited[n - i + 1])
        {
            dfs(n - i + 1);
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}