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

int k;

void fun(vector<int> lst)
{
    // for (auto x : lst)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    int index = k, n = lst.size();
    if (!n)
        return;
    if (n == 1)
    {
        cout << lst[0];
        return;
    }
    vector<int> toSend;
    if (n <= k)
    {
        int lcl = k % n;
        for (int i = 0; i < n; i++)
        {
            if (i != lcl)
            {
                toSend.push_back(lst[i]);
            }
            else
            {
                cout << lst[i] << " ";
                lcl += (k + 1);
            }
        }
        fun(toSend);
    }
    else
    {
        int mod = n % (k + 1);
        for (int i = n - mod; i < n; i++)
        {
            toSend.push_back(lst[i]);
        }
        for (int i = 0; i < n - mod; i++)
        {
            if (i != index)
            {
                toSend.push_back(lst[i]);
            }
            else
            {
                cout << lst[i] << " ";
                index += (k + 1);
            }
        }
        fun(toSend);
    }
}

int main()
{
    file_i_o();
    int n;
    cin >> n >> k;
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        lst[i] = i + 1;
    }
    fun(lst);
    return 0;
}