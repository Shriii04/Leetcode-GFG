//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Recurssion
// class Solution{
//   public:
//     int solve(int ind,int price[],int n){
//         if(ind==0){
//             return n*price[0];
//         }
//         int nottake = solve(ind-1,price,n);
//         int take = INT_MIN;
//         int rod_length = ind+1;
//         if(rod_length<=n){
//             take = price[ind]+solve(ind,price,n-rod_length);
//         }
//         return max(take,nottake);
//     }
//     int cutRod(int price[], int n) {
//         //code here
//         int ans = solve(n-1,price,n);
//         return ans;
//     }
// };

// Memoisation

class Solution{
  public:
    int solve(int ind,int price[],int n,vector<vector<int>> &dp){
        if(ind==0){
            return n*price[0];
        }
        if(dp[ind][n]!=-1) return dp[ind][n];
        int nottake = solve(ind-1,price,n,dp);
        int take = INT_MIN;
        int rod_length = ind+1;
        if(rod_length<=n){
            take = price[ind]+solve(ind,price,n-rod_length,dp);
        }
        return dp[ind][n] = max(take,nottake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int ans = solve(n-1,price,n,dp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends