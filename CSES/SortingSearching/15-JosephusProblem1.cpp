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

void fun(vector<int> lst)
{
    int index = 1, n = lst.size();
    if (n == 1)
    {
        cout << lst[0];
        return;
    }
    vector<int> toSend;
    if (n & 1)
    {
        toSend.push_back(lst[n - 1]);
        n--;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != index)
        {
            toSend.push_back(lst[i]);
        }
        else
        {
            cout << lst[i] << " ";
            index += 2;
        }
    }
    fun(toSend);
}

int main()
{
    file_i_o();
    int n;
    cin >> n;
    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        lst[i] = i + 1;
    }
    fun(lst);
    return 0;
}