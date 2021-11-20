#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
vector<int> ans;

void dfs(int root, int pre)
{
    for (auto node : adj[root])
    {
        if (node != pre)
        {
            if (!visited[node])
            {
                visited[node] = true;
                parent[node] = root;
                dfs(node, root);
            }
            else
            {
                int num = root;
                while (num != node)
                {
                    ans.push_back(num);
                    num = parent[num];
                }
                ans.push_back(num);
                ans.push_back(root);

                cout << ans.size() << "\n";
                for (auto x : ans)
                {
                    cout << x << " ";
                }
                exit(0);
                return;
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

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            dfs(i, 0);
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}