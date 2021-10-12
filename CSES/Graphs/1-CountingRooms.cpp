#include <bits/stdc++.h>
using namespace std;
const int INF = 1e4;
int n, m;
vector<vector<char>> graph;
queue<pair<int, int>> q;
vector<int> lx = {-1, 1, 0, 0};
vector<int> ly = {0, 0, -1, 1};

bool isValid(int s, int t)
{
    if (s >= 1 && s <= n && t >= 1 && t <= m && graph[s][t] == '.')
    {
        return true;
    }
    return false;
}

void bfs(int x, int y)
{
    graph[x][y] = '#';
    q.push({x, y});
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int s = lx[i] + a;
            int t = ly[i] + b;
            if (isValid(s, t))
            {
                graph[s][t] = '#';
                q.push({s, t});
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
    int ans = 0;
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        graph[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (graph[i][j] == '.')
            {
                bfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}