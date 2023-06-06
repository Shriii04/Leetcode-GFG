class Solution {
    public int majorityElement(int[] nums) {
        int major=0;
        if(nums.length==1){
            return nums[0];
        }
        Arrays.sort(nums);
        int count=0;
        int max=0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
                if(count>max){
                    max=count;
                    major=nums[i];
                }
            }
                else{
                    count=0;
                }
            }
            return major;
    }
};
        