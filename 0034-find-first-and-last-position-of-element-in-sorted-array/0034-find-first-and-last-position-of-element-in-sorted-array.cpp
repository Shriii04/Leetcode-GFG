class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>  ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                ans.push_back(i);
                break;
            } 
        }
        for(int j=nums.size()-1;j>=0;j--){
            if(nums[j]==target){
                ans.push_back(j);
                break;
            }
        }
        if(ans.empty()){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};