// https : //practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n)
    {
        vector<int> dp(w + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = w; j >= 0; j--)
            {
                if (j >= wt[i - 1])
                {
                    dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
                }
                else
                {
                    dp[j] = dp[j];
                }
            }
        }
        return dp[w];
    }
};

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
} // } Driver Code Ends