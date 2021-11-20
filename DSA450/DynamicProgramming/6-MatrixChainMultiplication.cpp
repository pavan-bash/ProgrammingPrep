// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int matrixMultiplication(int n, int arr[])
    {
        n--;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int gap = 1; gap < n; gap++)
        {
            for (int i = 0, j = i + gap; j < n; i++, j++)
            {
                int mini = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    mini = min(mini, dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][n - 1];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
} // } Driver Code Ends