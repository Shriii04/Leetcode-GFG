//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int index,int sum,vector<int>&arr,vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(index==0) return (arr[index]==sum);
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        bool nottake = f(index-1,sum,arr,dp);
        bool take = false;
        if(sum>=arr[index]){
            take = f(index-1,sum-arr[index],arr,dp);
        }
        return dp[index][sum] = take | nottake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends