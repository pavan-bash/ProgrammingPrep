#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph, dist;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
vector<int> lx = {1, -1, 0, 0};
vector<int> ly = {0, 0, 1, -1};
int n, m;

bool check(int a, int b)
{
    if (a >= 1 && a <= n && b >= 1 && b <= m && !visited[a][b])
    {
        return true;
    }
    return false;
}

void bfs(int x, int y)
{
    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        cout << graph[p.first][p.second] << " ";

        for (int i = 0; i < 4; i++)
        {
            int a = p.first + lx[i];
            int b = p.second + ly[i];
            if (check(a, b))
            {
                q.push({a, b});
                visited[a][b] = true;
                dist[a][b] = dist[p.first][p.second] + 1;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    graph.resize(n + 1);
    dist.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        graph[i].resize(m + 1);
        dist[i].resize(m + 1);
        visited[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    bfs(x, y);
    cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}