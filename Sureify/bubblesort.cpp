#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &lst)
{
    int n = lst.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (lst[i] > lst[j])
            {
                swap(lst[i], lst[j]);
            }
        }
    }
}

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

    bubblesort(lst);

    for (int i = 0; i < n; i++)
    {
        cout << lst[i] << " ";
    }
    return 0;
}