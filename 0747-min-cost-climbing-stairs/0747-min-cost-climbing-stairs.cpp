class Solution {
public:
    int solve(vector<int>& cost,int index,vector<int> &dp){
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int left = solve(cost,index-1,dp) + cost[index];
        int  right = solve(cost,index-2,dp) + cost[index];
        return dp[index] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        int a = min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return a;
    }
};