#include <bits/stdc++.h>
using namespace std;

vector<string> fun(vector<string> lst, int t)
{
    vector<string> ans;
    unordered_map<string, int> m;
    for (auto x : lst)
    {
        int p = 0;
        string s1 = "";
        while ((int)x[p] != 32)
        {
            s1 += x[p];
            p++;
        }
        string s2 = "";
        p++;
        while ((int)x[p] != 32)
        {
            s2 += x[p];
            p++;
        }
        m[s1]++;
        if (s1 != s2)
        {
            m[s2]++;
        }
    }
    for (auto x : m)
    {
        if (x.second >= t)
        {
            ans.push_back(x.first);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int t;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        string it;
        cin >> it;
        s[i] += it;
        s[i] += " ";
        cin >> it;
        s[i] += it;
        s[i] += " ";
        cin >> it;
        s[i] += it;
    }
    cin >> t;
    vector<string> ans = fun(s, t);
    for (auto x : ans)
    {
        cout << x << "\n";
    }
}