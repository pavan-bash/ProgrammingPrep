#include <bits/stdc++.h>
using namespace std;

int rows, cols;
vector<vector<char>> grid;
vector<int> lx = {-1, 1, 0, 0};
vector<int> ly = {0, 0, -1, 1};
vector<char> lz = {'U', 'D', 'L', 'R'};
vector<char> path;
bool check = false;

bool isValid(int x, int y)
{
    if (1 <= x && x <= rows && 1 <= y && y <= cols && grid[x][y] != '#')
    {
        return true;
    }
    return false;
}

void dfs(int x, int y)
{
    grid[x][y] = '#';
    for (int i = 0; i < 4; i++)
    {
        int currX = x + lx[i];
        int currY = y + ly[i];
        if (isValid(currX, currY))
        {
            if (grid[currX][currY] == 'B')
            {
                path.push_back(lz[i]);
                grid[currX][currY] = '#';
                check = true;
                return;
            }
            if (!check)
            {
                path.push_back(lz[i]);
            }
            dfs(currX, currY);
            if (!check)
            {
                path.pop_back();
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
    pair<int, int> start;
    grid.resize(rows + 1);
    for (int i = 1; i <= rows; i++)
    {
        grid[i].resize(cols + 1);
        for (int j = 1; j <= cols; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
        }
    }
    dfs(start.first, start.second);
    int sz = path.size();
    if (!sz)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        cout << path.size() << "\n";
        for (auto x : path)
        {
            cout << x;
        }
    }
    return 0;
}