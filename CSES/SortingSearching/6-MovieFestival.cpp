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

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int binarySearch(vector<pair<int, int>> movies, int i)
{
    int low = 0, high = i - 1, key = movies[i].first;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (movies[mid].second < key)
        {
            low = mid + 1;
        }
        else if (movies[mid].second > key)
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
    vector<pair<int, int>> movies(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), cmp);
    int interval = -1;
    for (auto movie : movies)
    {
        if (interval <= movie.first)
        {
            ans++;
            interval = movie.second;
        }
    }
    cout << ans;
    return 0;
}