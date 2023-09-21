class Solution {
public:
    int solve(int ind,vector<int>&nums,int s2,vector<vector<int>> &dp){
        if(ind==0){
            if(s2==0 && nums[0]==0) return 2;
            if(s2==0 || nums[0]==s2) return 1;
            return 0;
        }
        if(dp[ind][s2]!=-1) return dp[ind][s2];
        int nottake = solve(ind-1,nums,s2,dp);
        int take = 0;
        if(nums[ind]<=s2){
            take = solve(ind-1,nums,s2-nums[ind],dp);
        }
        return dp[ind][s2] = take+nottake;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = 0;
        for(auto x:nums){
            totalsum+=x;
        }

        if(totalsum-target<0) return 0;
        if((totalsum-target)%2==1) return 0;
        int s2 = (totalsum-target)/2;
        vector<vector<int>> dp(nums.size(),vector<int>(s2+1,-1));
        int ans = solve(nums.size()-1,nums,s2,dp);
        return ans;
    }
};