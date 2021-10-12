#include <bits/stdc++.h>
using namespace std;

const int INF = 1001;

vector<vector<char>> graph(INF, vector<char>(INF));
vector<vector<bool>> visited(INF, vector<bool>(INF));
vector<pair<int, int>> monsters;
vector<vector<int>> dist(INF, vector<int>(INF, -1)), distm(INF, vector<int>(INF, INF));
vector<vector<int>> cdist(INF, vector<int>(INF));
int n, m, sx, sy;
vector<int> lx = {-1, 1, 0, 0};
vector<int> ly = {0, 0, -1, 1};
vector<char> lz = {'D', 'U', 'R', 'L'};
queue<pair<int, int>> q;

bool isValid(int a, int b)
{
    if (a >= 1 && a <= n && b >= 1 && b <= m && !visited[a][b] && graph[a][b] != '#')
    {
        return true;
    }
    return false;
}

bool isCorner(int a, int b)
{
    if (1 < a && a < n && 1 < b && b < m)
    {
        return false;
    }
    return true;
}

bool check(int x, int y, int val)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m && dist[x][y] == val - 1)
    {
        return true;
    }
    return false;
}

void bfsm(int startx, int starty)
{
    fill(cdist.begin(), cdist.end(), vector<int>(m + 1, 0));
    fill(visited.begin(), visited.end(), vector<bool>(m + 1, false));
    visited[startx][starty] = true;
    q.push({startx, starty});
    cdist[startx][starty] = 0;
    distm[startx][starty] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = lx[i] + x;
            int b = ly[i] + y;
            if (isValid(a, b))
            {
                visited[a][b] = true;
                q.push({a, b});
                cdist[a][b] = cdist[x][y] + 1;
                distm[a][b] = min(distm[a][b], cdist[a][b]);
            }
        }
    }
}

pair<int, int> bfs(int startx, int starty)
{
    fill(visited.begin(), visited.end(), vector<bool>(m + 1, false));
    visited[startx][starty] = true;
    q.push({startx, starty});
    dist[startx][starty] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = lx[i] + x;
            int b = ly[i] + y;
            if (isValid(a, b))
            {
                dist[a][b] = dist[x][y] + 1;
                if (dist[a][b] < distm[a][b])
                {
                    if (isCorner(a, b))
                        return {a, b};
                    visited[a][b] = true;
                    q.push({a, b});
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return {-1, -1};
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            else if (graph[i][j] == 'M')
            {
                monsters.push_back({i, j});
            }
        }
    }

    for (auto x : monsters)
    {
        int a = x.first;
        int b = x.second;
        bfsm(a, b);
    }

    if (isCorner(sx, sy))
    {
        cout << "YES\n0";
        return 0;
    }

    pair<int, int> o = bfs(sx, sy);
    int endx = o.first;
    int endy = o.second;

    if (endx == -1)
    {
        cout << "NO";
        return 0;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dist[i][j] << " ";
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
            if (check(x, y, dist[endx][endy]))
            {
                endx = x;
                endy = y;
                ans.push_back(lz[i]);
                break;
            }
        }
        // if (i == 4)
        // {
        //     cout << "NO";
        //     return 0;
        // }
    } while (endx != sx || endy != sy);

    reverse(ans.begin(), ans.end());
    cout << "YES\n"
         << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x;
    }
    return 0;
}