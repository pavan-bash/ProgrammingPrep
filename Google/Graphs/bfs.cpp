#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
queue<int> q;
vector<int> dist;

void bfs(int startNode)
{
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty())
    {
        int root = q.front();
        q.pop();
        cout << root << " ";
        for (auto node : adj[root])
        {
            if (!visited[node])
            {
                q.push(node);
                visited[node] = true;
                dist[node] = dist[root] + 1;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nodes, edges;
    cin >> nodes >> edges;
    adj.resize(nodes + 1);
    visited.resize(nodes + 1);
    dist.resize(nodes + 1);
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int startNode;
    cin >> startNode;
    bfs(startNode);
    cout << "\n";
    for (int i = 1; i <= nodes; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}