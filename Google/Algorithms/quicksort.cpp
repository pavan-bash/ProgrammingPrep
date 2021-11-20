#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int partition(int low, int high)
{
    int pivot = a[low];
    int i = low, j = high + 1;

    while (i < j)
    {
        i++;
        while (a[i] < pivot)
        {
            i++;
        }
        j--;
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[j]);
    return j;
}

void quicksort(int low, int high)
{
    if (low < high)
    {
        int j = partition(low, high);
        quicksort(low, j - 1);
        quicksort(j + 1, high);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quicksort(0, n - 1);
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}