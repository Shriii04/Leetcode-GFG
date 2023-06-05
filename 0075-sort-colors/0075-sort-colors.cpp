class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0,ones=0,twos=0;
        for(auto i : nums){
            if(i==0){
                zeros++;
            }
            else if(i==1){
                ones++;
            }
            else{
                twos++;
            }
        }
        int j=0;
        for(int i=0;i<zeros;i++){
            nums[j++]=0;
        }
        for(int i=0;i<ones;i++){
            nums[j++]=1;
        }
        for(int i=0;i<twos;i++){
            nums[j++]=2;
        }
    }
};