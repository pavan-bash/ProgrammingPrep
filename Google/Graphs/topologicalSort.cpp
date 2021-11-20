#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited, topologicalOrdering;
bool check = false;

void dfs(int root)
{
    if (visited[root] == 1)
    {
        check = true;
        return;
    }
    visited[root] = 1;

    for (auto node : adj[root])
    {
        if (visited[node] != 2)
        {
            dfs(node);
        }
    }
    visited[root] = 2;
    topologicalOrdering.push_back(root);
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
    }

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    if (check)
    {
        cout << "Cycle Detected";
        return 0;
    }
    reverse(topologicalOrdering.begin(), topologicalOrdering.end());
    for (auto x : topologicalOrdering)
    {
        cout << x << " ";
    }

    return 0;
}