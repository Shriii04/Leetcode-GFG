class Solution {
public:
    
    int solve(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i >= n)  return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i]+solve(nums,i+2,n,dp);
        int nottake = solve(nums,i+1,n,dp);
        return dp[i]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,n,dp);
    }
};