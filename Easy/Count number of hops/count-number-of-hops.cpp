//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long mod = 1000000007;
    long long solve(int n,vector<long long>&dp){
        if(n==0) return 1;
        if(n==1 ||n==2) return n;
        if(dp[n]!=-1) return dp[n];
        long long  a = solve(n-1,dp);
        long long b = solve(n-2,dp);
        long long c = solve(n-3,dp);
        
        return dp[n]=(a+b+c)%mod;
    }
    long long countWays(int n)
    {
        
        // your code here
        vector<long long> dp(n+1,-1);
        return solve(n,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends