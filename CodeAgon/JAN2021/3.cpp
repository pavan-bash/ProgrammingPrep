#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &lst)
{
    if (lst.size() == 1)
    {
        return 0;
    }
    unordered_map<int, int> m;
    int ans = 0;
    for (auto x : lst)
    {
        ans += x;
        m[x]++;
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }
    cout << solve(lst);
    return 0;
}