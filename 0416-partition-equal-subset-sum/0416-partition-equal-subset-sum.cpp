class Solution {
public:
    bool f(int index,int target,vector<int> &nums, vector<vector<int>> &dp){
        if(target ==0) return true;
        if(index==0) return (nums[index]==target);
        if(dp[index][target]!=-1) return dp[index][target];
        int nottake = f(index-1,target,nums,dp);
        int take = false;
        if(target>=nums[index]){
            take = f(index-1,target-nums[index],nums,dp);
        }
        return dp[index][target] = take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i=0;i<nums.size();i++) total +=nums[i];
        int target = total/2;
        if(total%2!=0) return false;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return f(nums.size()-1,target,nums,dp);
    }
};