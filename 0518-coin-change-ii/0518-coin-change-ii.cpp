class Solution {
public:
    int solve(int ind,vector<int>&coins,int target,vector<vector<int>> &dp){
        if(ind == 0){
            return (target%coins[0]==0);
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
            int nottake = solve(ind-1,coins,target,dp);
            int take = 0;
            if(coins[ind]<=target){
                take = solve(ind,coins,target-coins[ind],dp);
            }
        return dp[ind][target] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(coins.size()-1,coins,amount,dp);
        return ans;
    }
};