#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> noOfNodes;

void dfs(int root, int parent)
{
    cout << root << " ";
    noOfNodes[root] = 1;
    for (auto node : tree[root])
    {
        if (node != parent)
        {
            // processing node
            dfs(node, root);
            // processing root
            noOfNodes[root] += noOfNodes[node];
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int nodes;
    cin >> nodes;
    tree.resize(nodes + 1);
    noOfNodes.resize(nodes + 1);
    int edges = nodes - 1;
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    int startNode;
    cin >> startNode;
    dfs(startNode, 0);

    cout << "\n";
    for (int i = 1; i <= nodes; i++)
    {
        cout << noOfNodes[i] << " ";
    }
    return 0;
}