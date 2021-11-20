// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        if (n == 1)
            return 0;
        if (arr[0] == 0)
            return -1;
        int jump = 1;
        int max_reach = arr[0];
        int step = arr[0];
        for (int i = 1; i < n - 1; i++)
        {
            step--;
            max_reach = max(max_reach, i + arr[i]);
            if (step == 0)
            {
                jump++;
                if (i >= max_reach)
                    return -1;
                step = max_reach - i;
            }
        }
        return jump;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends