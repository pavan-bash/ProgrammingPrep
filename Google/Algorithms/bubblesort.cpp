#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> lst(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (lst[i] > lst[j])
            {
                swap(lst[i], lst[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << lst[i] << " ";
    }
    return 0;
}