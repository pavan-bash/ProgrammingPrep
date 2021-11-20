#include <bits/stdc++.h>
using namespace std;

int rows, cols;
vector<vector<char>> grid;
vector<int> lx = {-1, 1, 0, 0};
vector<int> ly = {0, 0, -1, 1};

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
            dfs(currX, currY);
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
    for (int i = 1; i <= rows; i++)
    {
        grid[i].resize(cols + 1);
        for (int j = 1; j <= cols; j++)
        {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            if (grid[i][j] == '.')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}