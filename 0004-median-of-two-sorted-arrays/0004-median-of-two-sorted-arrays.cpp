class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // int m = nums1.size();
    // int n = nums2.size();

    // if (m > n) {
    //     // Ensure nums1 is the shorter array
    //     swap(nums1, nums2);
    //     swap(m, n);
    // }

    // int low = 0;
    // int high = m;

    // while (low <= high) {
    //     int partition1 = (low + high) / 2;
    //     int partition2 = (m + n + 1) / 2 - partition1;

    //     int leftMax1 = (partition1 == 0) ? INT32_MIN : nums1[partition1 - 1];
    //     int rightMin1 = (partition1 == m) ? INT32_MAX : nums1[partition1];
    //     int leftMax2 = (partition2 == 0) ? INT32_MIN : nums2[partition2 - 1];
    //     int rightMin2 = (partition2 == n) ? INT32_MAX : nums2[partition2];

    //     if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
    //         // Correct partition found
    //         if ((m + n) % 2 == 0) {
    //             // Even length, return average of middle elements
    //             return (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2.0;
    //         } else {
    //             // Odd length, return the middle element
    //             return max(leftMax1, leftMax2);
    //         }
    //     } else if (leftMax1 > rightMin2) {
    //         // Move partition1 to the left
    //         high = partition1 - 1;
    //     } else {
    //         // Move partition1 to the right
    //         low = partition1 + 1;
    //     }
    // }

    // // No median found
    // return 0.0;
    for(int i=0;i<nums2.size();i++){
        nums1.push_back(nums2[i]);
    }
    int n = nums1.size();
    sort(nums1.begin(),nums1.end());
    if(n%2!=0){
        return nums1[(n/2)];
    }
    else{
        return (double) (nums1[(n/2)] + nums1[(n/2)-1] ) /2 ;
    }
    }
};