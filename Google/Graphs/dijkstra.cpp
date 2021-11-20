#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dist, parent;
vector<bool> visited;
priority_queue<pair<int, int>> q;

void dijkstra(int startNode)
{
    q.push({0, startNode});
    dist[startNode] = 0;
    while (!q.empty())
    {
        pair<int, int> root = q.top();
        q.pop();
        if (visited[root.second])
        {
            continue;
        }
        visited[root.second] = true;
        for (auto node : adj[root.second])
        {
            if (dist[node.first] > dist[root.second] + node.second)
            {
                dist[node.first] = dist[root.second] + node.second;
                q.push({-dist[node.first], node.first});
                parent[node.first] = root.second;
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
    dist.resize(nodes + 1, INT_MAX);
    parent.resize(nodes + 1);
    visited.resize(nodes + 1);
    for (int i = 0; i < edges; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    int startNode;
    cin >> startNode;

    dijkstra(startNode);

    for (int i = 1; i <= nodes; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";

    for (int i = 1; i <= nodes; i++)
    {
        if (i != startNode)
        {
            int j = i;
            cout << j << ": ";
            do
            {
                cout << j << " <- ";
                j = parent[j];
            } while (j != startNode);
            cout << j << "\n";
        }
    }

    return 0;
}