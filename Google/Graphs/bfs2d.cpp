#include <bits/stdc++.h>
using namespace std;

int rows, columns;
vector<vector<int>> grid, dist;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

vector<int> lx = {-1, 1, 0, 0};
vector<int> ly = {0, 0, -1, 1};

bool isValid(int currX, int currY)
{
    if (1 <= currX && currX <= rows && 1 <= currY && currY <= columns && !visited[currX][currY])
    {
        return true;
    }
    return false;
}

void bfs(int startX, int startY)
{
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty())
    {
        pair<int, int> root = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int currX = root.first + lx[i];
            int currY = root.second + ly[i];
            if (isValid(currX, currY))
            {
                q.push({currX, currY});
                visited[currX][currY] = true;
                dist[currX][currY] = dist[root.first][root.second] + 1;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> rows >> columns;
    grid.resize(rows + 1);
    dist.resize(rows + 1);
    visited.resize(rows + 1);
    for (int i = 1; i <= rows; i++)
    {
        grid[i].resize(columns + 1);
        dist[i].resize(columns + 1);
        visited[i].resize(columns + 1);
        for (int j = 1; j <= columns; j++)
        {
            cin >> grid[i][j];
        }
    }
    int startX, startY;
    cin >> startX >> startY;
    bfs(startX, startY);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}