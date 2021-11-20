#include <bits/stdc++.h>
using namespace std;

int rows, cols;
vector<vector<char>> grid, dir;
vector<int> lx = {-1, 1, 0, 0};
vector<int> ly = {0, 0, -1, 1};
vector<char> lz = {'D', 'U', 'R', 'L'};
vector<char> la = {'U', 'D', 'L', 'R'};
vector<char> path;
pair<int, int> start;
queue<pair<int, int>> q;

bool isValid(int x, int y)
{
    if (1 <= x && x <= rows && 1 <= y && y <= cols && grid[x][y] != '#')
    {
        return true;
    }
    return false;
}

void bfs(int x, int y)
{
    q.push({x, y});
    grid[x][y] = '#';

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int currX = node.first + lx[i];
            int currY = node.second + ly[i];
            if (isValid(currX, currY))
            {
                if (grid[currX][currY] == 'B')
                {
                    int a = node.first, b = node.second;
                    path.push_back(la[i]);
                    do
                    {
                        if (dir[a][b] == 'D')
                        {
                            a++;
                            path.push_back('U');
                        }
                        else if (dir[a][b] == 'L')
                        {
                            b--;
                            path.push_back('R');
                        }
                        else if (dir[a][b] == 'U')
                        {
                            a--;
                            path.push_back('D');
                        }
                        else if (dir[a][b] == 'R')
                        {
                            b++;
                            path.push_back('L');
                        }
                    } while (a != start.first || b != start.second);
                    return;
                }
                grid[currX][currY] = '#';
                dir[currX][currY] = lz[i];
                q.push({currX, currY});
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
    cin >> rows >> cols;
    grid.resize(rows + 1);
    dir.resize(rows + 1);
    for (int i = 1; i <= rows; i++)
    {
        grid[i].resize(cols + 1);
        dir[i].resize(cols + 1, 'x');
        for (int j = 1; j <= cols; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
        }
    }
    bfs(start.first, start.second);
    int sz = path.size();
    if (!sz)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        cout << path.size() << "\n";
        reverse(path.begin(), path.end());
        for (auto x : path)
        {
            cout << x;
        }
    }
    return 0;
}