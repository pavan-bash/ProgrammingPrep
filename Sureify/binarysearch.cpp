#include <bits/stdc++.h>
using namespace std;
vector<int> lst;

int bs(int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (lst[mid] == key)
        {
            return mid;
        }
        else if (lst[mid] < key)
        {
            return bs(mid + 1, high, key);
        }
        else
        {
            return bs(low, mid - 1, key);
        }
    }
    return -1;
}

int bsit(int key)
{
    int low = 0;
    int high = lst.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (lst[mid] == key)
        {
            return mid;
        }
        else if (lst[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    lst.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }
    int key;
    cin >> key;
    cout << bs(0, n - 1, key) + 1 << endl;
    cout << bsit(key) + 1;
    return 0;
}