//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e9+7;
    int solve(int ind,vector<int>& arr,int s2,vector<vector<int>>&dp){
        if(ind == 0){
            if(s2==0 && arr[0]==0) return 2;
            if(s2==0 || arr[0]==s2) return 1;
            return 0;
        }
        if(dp[ind][s2]!=-1) return dp[ind][s2];
        int nottake = solve(ind-1,arr,s2,dp);
        int take =0;
        if(arr[ind]<=s2){
            take = solve(ind-1,arr,s2-arr[ind],dp);
        }
        return dp[ind][s2] = (take+nottake)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum+=arr[i];
        }
        
        if(totalSum-d<0) return 0;
        if((totalSum-d)%2!=0) return 0;
        
        int s2 = (totalSum-d)/2;
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return solve(n-1,arr,s2,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends