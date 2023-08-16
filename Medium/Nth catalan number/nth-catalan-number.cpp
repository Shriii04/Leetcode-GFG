//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    long long mod = 1000000007;

    // int find(int open, int close, vector<vector<long long>>& dp) {
    //     if (open == 0 && close == 0) return 1;
    //     if (open < 0 || close < 0) return 0;
    //     if (dp[open][close] != -1) return dp[open][close];
    //     long long o = find(open - 1, close, dp);
    //     long long c = 0;
    //     if (close > open) {
    //         c = find(open, close - 1, dp);
    //     }
    //     return dp[open][close] = (o + c) % mod;
    // }

// int findCatalan(int n) {
//     // vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
//     // return find(n, n, dp);
//     const int mod = 1000000007;

int findCatalan(int n) {
    vector<long long> catalan(n + 1, 0);
    catalan[0] = catalan[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan[i] = (catalan[i] + (catalan[j] * catalan[i - j - 1]) % mod) % mod;
        }
    }

    return catalan[n];
}


};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends