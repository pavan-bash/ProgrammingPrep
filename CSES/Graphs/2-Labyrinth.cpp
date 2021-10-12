#include <bits/stdc++.h>
using namespace std;
const int INF = 1e4;
int n, m;
int startx, starty, endx, endy;
vector<vector<int>> graph;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
vector<int> lx = {-1, 1, 0, 0};
vector<int> ly = {0, 0, -1, 1};
vector<char> lz = {'D', 'U', 'R', 'L'};

bool isValid(int s, int t)
{
    if (s >= 1 && s <= n && t >= 1 && t <= m && !visited[s][t] && graph[s][t] != -1)
    {
        return true;
    }
    return false;
}

bool check(int x, int y, int val)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m && graph[x][y] == val - 1)
    {
        return true;
    }
    return false;
}

void bfs(int x, int y)
{
    q.push({x, y});
    visited[x][y] = true;
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
                q.push({s, t});
                graph[s][t] = graph[a][b] + 1;
                visited[s][t] = true;
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
    visited.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        graph[i].resize(m + 1);
        visited[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == 'A')
            {
                startx = i;
                starty = j;
            }
            else if (c == 'B')
            {
                endx = i;
                endy = j;
            }
            else if (c == '#')
            {
                graph[i][j] = -1;
            }
        }
    }
    bfs(startx, starty);

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vector<char> ans;

    do
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            int x = endx + lx[i];
            int y = endy + ly[i];
            if (check(x, y, graph[endx][endy]))
            {
                endx = x;
                endy = y;
                ans.push_back(lz[i]);
                break;
            }
        }
        if (i == 4)
        {
            cout << "NO";
            return 0;
        }
    } while (endx != startx || endy != starty);

    reverse(ans.begin(), ans.end());
    cout << "YES\n"
         << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x;
    }
    return 0;
}