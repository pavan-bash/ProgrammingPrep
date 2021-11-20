#include <bits/stdc++.h>
using namespace std;

vector<int> lst;

int bs(int key)
{
    int low = 0, high = lst.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (lst[mid] == key)
            return mid;
        if (lst[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int bsr(int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (lst[mid] == key)
            return mid;
        if (lst[mid] < key)
            return bsr(mid + 1, high, key);
        else
            return bsr(low, mid - 1, key);
    }
    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, key;
    cin >> n >> key;
    lst.resize(n);
    for (int i = 0; i < n; i++)
        cin >> lst[i];
    cout << bs(key) << endl;
    cout << bsr(0, n - 1, key) << endl;
    return 0;
}