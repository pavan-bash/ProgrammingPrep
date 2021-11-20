#include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int j;
        for (j = 0; j < i; j++)
        {
            if (a[j] > a[i])
            {
                break;
            }
        }
        int c = a[i];
        for (int k = i - 1; k >= j; k--)
        {
            a[k + 1] = a[k];
        }
        a[j] = c;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertionsort(a);
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}