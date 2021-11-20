#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    if (n == 1)
    {
        cout << grid[0][0];
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                grid[i][j] += max(grid[i - 1][j], grid[i - 1][j + 1]);
            }
            else if (j == n - 1)
            {
                grid[i][j] += max(grid[i - 1][j], grid[i - 1][j - 1]);
            }
            else
            {
                grid[i][j] += max({grid[i - 1][j + 1], grid[i - 1][j], grid[i - 1][j - 1]});
            }
        }
    }
    cout << *max_element(grid[n - 1].begin(), grid[n - 1].end());

    return 0;
}