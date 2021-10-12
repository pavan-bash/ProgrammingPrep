#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll minimumOperations(vector<int> lst)
{
    ll ans = 0;
    multiset<int> s;
    for (auto x : lst)
    {
        ans++;
        auto itr = s.find(x);
        auto it = itr;
        int diff1, diff2;
        if (itr == s.end())
        {
            itr = s.insert(x);
            diff1 = distance(s.begin(), itr);
            diff2 = distance(itr, s.end());
        }
        else
        {
            it = s.insert(x);
            diff1 = distance(s.begin(), itr);
            diff2 = distance(it, s.end());
        }
        diff2--;
        ans += min(diff1 * 2, diff2 * 2);
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> lst(n);
        for (int i = 0; i < n; i++)
        {
            cin >> lst[i];
        }
        cout << minimumOperations(lst) << "\n";
    }
    return 0;
}