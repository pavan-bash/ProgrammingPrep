#include <bits/stdc++.h>
using namespace std;

#define int long long

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

int32_t main()
{
    file_i_o();
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 1e12));
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = min(w, graph[a][b]);
        graph[b][a] = min(w, graph[b][a]);
    }
    for (int i = 1; i <= n; i++)
    {
        graph[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (graph[x][y] == 1e12)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << graph[x][y] << "\n";
        }
    }
    return 0;
}