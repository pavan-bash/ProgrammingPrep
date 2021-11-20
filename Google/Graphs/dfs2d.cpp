#include <bits/stdc++.h>
using namespace std;

int rows, cols;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<int> lx = {-1, 1, 0, 0};
vector<int> ly = {0, 0, -1, 1};

bool isValid(int currX, int currY)
{
    if (1 <= currX && currX <= rows && 1 <= currY && currY <= cols && !visited[currX][currY])
    {
        return true;
    }
    return false;
}

int dfs(int rootX, int rootY)
{
    visited[rootX][rootY] = true;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int currX = rootX + lx[i];
        int currY = rootY + ly[i];
        if (isValid(currX, currY) && grid[rootX][rootY] == grid[currX][currY])
        {
            sum += dfs(currX, currY);
        }
    }
    return sum + 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> rows >> cols;
    grid.resize(rows + 1);
    visited.resize(rows + 1);
    for (int i = 1; i <= rows; i++)
    {
        grid[i].resize(cols + 1);
        visited[i].resize(cols + 1);
        for (int j = 1; j <= cols; j++)
        {
            cin >> grid[i][j];
        }
    }
    int ans = -1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            if (!visited[i][j])
            {
                ans = max(ans, dfs(i, j));
            }
        }
    }
    cout << ans;
    return 0;
}