class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a =nums1.size();
        for(int i=a-1;i>=m;i--){
            nums1[i]=nums2[n-1];
            n--;
        }
        sort(nums1.begin(),nums1.end());
    }
};