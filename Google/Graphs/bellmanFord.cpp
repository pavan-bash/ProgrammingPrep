#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nodes, noedges;
    cin >> nodes >> noedges;

    vector<tuple<int, int, int>> edges;
    vector<int> dist(nodes, 1e6);

    for (int i = 0; i < noedges; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    int startNode;
    cin >> startNode;
    dist[startNode] = 0;

    for (int i = 1; i < nodes; i++)
    {
        for (auto edge : edges)
        {
            int x, y, w;
            tie(x, y, w) = edge;
            dist[y] = min(dist[y], dist[x] + w);
        }
    }

    for (int i = 1; i <= nodes; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}