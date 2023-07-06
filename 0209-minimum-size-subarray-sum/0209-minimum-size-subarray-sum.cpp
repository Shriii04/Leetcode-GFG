class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0 ,current = 0;
        int res = INT_MAX;
        
        for(right=0;right<nums.size();right++){
            current+=nums[right];
            while(target<=current){
                current-=nums[left];
                res = min(res,right-left+1);
                left++;
            }
        }
        if(res==INT_MAX){
            return 0;
        }
        return res;
    }
};