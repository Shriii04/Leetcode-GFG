class Solution {
public:
    int solve(vector<int>& nums,int i,int end,vector<int>& dp){
        if(i == end)  return nums[end];
        if(i> end) return 0;
        if(dp[i]!=-1) return dp[i];

        int take1 = nums[i]+solve(nums,i+2,end,dp);
        int take2 = solve(nums,i+1,end,dp);
        return dp[i]=max(take1,take2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,-1);
        vector<int> dp2(n+1,-1);
        int ans1 = solve(nums,0,n-2,dp);
        int ans2 = solve(nums,1,n-1,dp2);
        return max(ans1,ans2);
    }
};