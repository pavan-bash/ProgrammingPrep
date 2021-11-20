#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int root)
{
    // Time Complexity : O(nodes + edges)
    if (visited[root])
    {
        return;
    }
    visited[root] = true;
    cout << root << " ";
    for (auto node : adj[root])
    {
        dfs(node);
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
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int startNode;
    cin >> startNode;
    dfs(startNode);
    return 0;
}