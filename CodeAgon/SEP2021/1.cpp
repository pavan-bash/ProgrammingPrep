#include <bits/stdc++.h>
using namespace std;

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
    int A, B;
    cin >> A >> B;
    int inf = 1e9 + 7;
    vector<vector<int>> dp(A + 1, vector<int>(B + 1));

    for (int i = 0; i <= A; i++)
    {
        if (i >= 2)
            dp[i][0] = 2;
        else
            dp[i][0] = i;
    }
    for (int i = 0; i <= B; i++)
    {
        if (i >= 2)
            dp[0][i] = 2;
        else
            dp[0][i] = i;
    }
    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 1; i <= A; i++)
    {
        for (int j = 1; j <= B; j++)
        {

            dp[i][j] = inf;
        }
    }
    for (int i = 1; i <= A; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            int s = floor(sqrt(i * j));
            dp[i][j] = min(min(dp[i / 2][j] + 1, 1 + dp[i][j / 2]), 2 + dp[s][s]);
        }
    }
    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[A][B];
    return 0;
}