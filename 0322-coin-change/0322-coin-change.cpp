class Solution {
public:
    int solve(int ind,vector<int>&coins,int target,vector<vector<int>> &dp){
        if(ind==0){
            if(target%coins[0]==0){
                return target/coins[0];
            }
            else return INT_MAX-1;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake = solve(ind-1,coins,target,dp);
        int take = INT_MAX;
        if(target>=coins[ind]){
            take = 1+solve(ind,coins,target-coins[ind],dp);
        }
        return dp[ind][target] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans = -1;
        ans = solve(coins.size()-1,coins,amount,dp);
        if(ans==INT_MAX || ans == INT_MAX-1){
           return -1;
       }
       return ans;
    }
};