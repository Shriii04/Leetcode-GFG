class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(sum>maxsum){
                maxsum=sum;
            }
            
            if(sum<0){
                sum=0;
            }
        }
        return maxsum;
    }
};