class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n=nums.size();
      int n1=1;
      if(n==0 || n==1){
          return n;
      }
      for(int i=0;i<n-1;i++){
          if(nums[i]<nums[i+1]){
              nums[n1]=nums[i+1];
              n1++;
          }
      }
      return n1;  
    }
};