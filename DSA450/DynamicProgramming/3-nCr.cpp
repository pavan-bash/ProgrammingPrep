// https://practice.geeksforgeeks.org/problems/ncr1019/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int mod = 1e9 + 7;
    int nCr(int n, int r)
    {
        if (n < r)
            return 0;
        vector<int> dp(r + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = r; j >= 1; j--)
            {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
        return dp[r];
    }
    int binomialCoeff(int n, int k)
    {
        int res = 1;
        // Since C(n, k) = C(n, n-k)
        if (k > n - k)
            k = n - k;

        // Calculate value of
        // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
        for (int i = 0; i < k; ++i)
        {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} // } Driver Code Ends