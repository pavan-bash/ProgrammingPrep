#include <bits/stdc++.h>
using namespace std;

void selectionsort(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[idx])
                idx = j;
        }
        swap(a[i], a[idx]);
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
    selectionsort(a);
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}