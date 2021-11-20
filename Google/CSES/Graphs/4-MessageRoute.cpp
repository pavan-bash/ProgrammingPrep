#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
queue<int> q;
vector<int> parent;

void bfs(int startNode)
{
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty())
    {
        int root = q.front();
        q.pop();
        for (auto node : adj[root])
        {
            if (!visited[node])
            {
                visited[node] = true;
                parent[node] = root;
                q.push(node);
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
    int nodes, edges;
    cin >> nodes >> edges;
    adj.resize(nodes + 1);
    visited.resize(nodes + 1);
    parent.resize(nodes + 1);
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1);
    if (!visited[nodes])
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int num = nodes;
    vector<int> ans;
    do
    {
        ans.push_back(num);
        num = parent[num];
    } while (num != 1);
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}