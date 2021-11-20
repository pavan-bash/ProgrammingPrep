#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> color;
queue<int> q;
bool check = true;

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
                q.push(node);
                if (color[root] == 1)
                {
                    color[node] = 2;
                }
                else
                {
                    color[node] = 1;
                }
            }
            else
            {
                if (color[node] == color[root])
                {
                    cout << "IMPOSSIBLE";
                    check = false;
                    return;
                }
            }
        }
    }
}

int main()
{
    file_i_o();
    int nodes, edges;
    cin >> nodes >> edges;
    adj.resize(nodes + 1);
    color.resize(nodes + 1);
    visited.resize(nodes + 1);
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            color[i] = 1;
            bfs(i);
            if (!check)
                return 0;
        }
    }

    for (int i = 1; i <= nodes; i++)
    {
        cout << color[i] << " ";
    }

    return 0;
}