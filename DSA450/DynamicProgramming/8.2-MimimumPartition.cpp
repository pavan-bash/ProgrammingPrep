// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        int sum = 0, sum_copy;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        sum_copy = sum;
        sum = sum / 2;
        vector<bool> dp(sum + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = sum; j >= arr[i - 1]; j--)
            {
                dp[j] = dp[j] || dp[j - arr[i - 1]];
            }
        }
        for (int i = sum; i >= 0; i--)
        {
            if (dp[i])
                return abs(2 * i - sum_copy);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends