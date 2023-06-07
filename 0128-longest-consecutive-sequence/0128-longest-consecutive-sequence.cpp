class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int ans=1;
        int curr=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a+1){
                curr++;
            }
            else if(nums[i]!=a){
                curr=1;
            }
            
            a=nums[i];
            ans=max(ans,curr);
        }
        return ans;
    }
};