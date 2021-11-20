// https: //practice.geeksforgeeks.org/problems/coin-change2448/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long int count(int arr[], int m, int n)
    {
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for (int j = 0; j < m; j++)
        {
            for (long long i = arr[j]; i <= n; i++)
            {
                dp[i] += dp[i - arr[j]];
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
} // } Driver Code Ends