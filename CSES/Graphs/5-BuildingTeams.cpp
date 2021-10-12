#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
queue<int> q;
vector<int> res;
int flag = 0;

void bfs(int start)
{
    visited[start] = true;
    res[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto x : graph[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
                if (res[v] == 1)
                {
                    res[x] = 2;
                }
                else if (res[v] == 2)
                {
                    res[x] = 1;
                }
            }
            else
            {
                if (res[v] == res[x])
                {
                    flag = 1;
                    return;
                }
            }
        }
    }
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
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1);
    res.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && !flag)
        {
            bfs(i);
        }
    }
    if (flag == 1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << res[i] << " ";
        }
    }
    return 0;
}