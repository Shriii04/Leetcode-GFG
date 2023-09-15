//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int sum,int arr[],vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(ind==0) return (arr[0]==sum);
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int nottake = solve(ind-1,sum,arr,dp);
        int take = 0;
        if(sum>arr[ind]){
            take = solve(ind-1,sum-arr[ind],arr,dp);
        }
        return dp[ind][sum] = take || nottake;
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int target = 0;
        int sum = 0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        target = sum/2;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        if(sum%2!=0){
            return 0;
        }
        else{
             return solve(N-1,target,arr,dp);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends