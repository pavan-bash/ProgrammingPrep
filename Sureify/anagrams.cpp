#include <bits/stdc++.h>
using namespace std;

int getAnagram(string s)
{
    int sz = s.size();
    int ans = 0;
    unordered_map<char, int> m1;
    for (int i = 0; i < sz / 2; i++)
    {
        m1[s[i]]++;
    }
    for (int i = sz / 2; i < sz; i++)
    {
        if (!m1[s[i]])
        {
            ans++;
        }
        else
        {
            m1[s[i]]--;
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        cout << getAnagram(s) << "\n";
    }
}