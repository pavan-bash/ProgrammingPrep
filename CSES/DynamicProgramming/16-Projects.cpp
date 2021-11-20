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

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
    {
        return a[2] > b[2];
    }
    return a[1] < b[1];
}

int binarySearch(int low, int high, vector<vector<int>> projects, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (projects[mid][1] < key)
        {
            low = mid + 1;
        }
        else if (projects[mid][1] > key)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return high;
}

int main()
{
    file_i_o();
    int n;
    cin >> n;
    vector<vector<int>> projects(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }
    sort(projects.begin(), projects.end(), cmp);

    vector<long long> dp(n);
    dp[0] = projects[0][2];
    for (int i = 1; i < n; i++)
    {
        int index = binarySearch(0, i - 1, projects, projects[i][0] - 1);
        if (index >= 0)
            dp[i] = max(dp[index] + projects[i][2], dp[i - 1]);
        else
            dp[i] = dp[i - 1];
    }
    cout << dp[n - 1];
    return 0;
}