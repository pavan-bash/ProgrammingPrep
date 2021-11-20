// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// { Driver Code Starts
//Initial Template for C

#include <stdio.h>

// } Driver Code Ends
//User function Template for C

void sort012(int a[], int n)
{
    int low = 0, high = n - 1;
    int mid = 0;
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            int t = a[low];
            a[low] = a[mid];
            a[mid] = t;
            low++;
            mid++;
        }
        else if (a[mid] == 2)
        {
            int t = a[high];
            a[high] = a[mid];
            a[mid] = t;
            high--;
        }
        else
        {
            mid++;
        }
    }
}

// { Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends