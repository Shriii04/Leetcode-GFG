class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        //int a = nums[k-1];
        int b = nums[nums.size()-k];
        return b;
    }
};