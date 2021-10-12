#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> dist, parent;
queue<int> q;

void bfs(int start)
{
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto x : graph[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
                dist[x] = dist[v] + 1;
                parent[x] = v;
            }
        }
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
    dist.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    if (!visited[n])
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> ans;
    ans.push_back(n);
    int end = n;

    do
    {
        end = parent[end];
        ans.push_back(end);
    } while (end != 1);

    reverse(ans.begin(), ans.end());

    int sz = ans.size();
    cout << sz << "\n";

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}