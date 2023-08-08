class Solution {
public:
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     set<vector<int>> set;
    //     vector<vector<int>> output;
    //     for(int i=0; i<n-3; i++){
    //         for(int j=i+1; j<n-2; j++){
    //             for(int k=j+1; k<n-1; k++){
    //                 for(int l=k+1; l<n; l++){
    //                     if((long long)nums[i] + (long long)nums[j] + (long long)nums[k] + 
    //                     (long long)nums[l] == target){
    //                         set.insert({nums[i], nums[j], nums[k], nums[l]});
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     for(auto it : set){
    //         output.push_back(it);
    //     }
    //     return output;
    // }
    
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<int> sortedNums(nums); 
    sort(sortedNums.begin(), sortedNums.end());
    int n = nums.size();
    vector<vector<int>> output;

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && sortedNums[i] == sortedNums[i - 1])
            continue;  // Skip duplicates

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && sortedNums[j] == sortedNums[j - 1])
                continue;  // Skip duplicates

            int left = j + 1;
            int right = n - 1;
            while (left < right) {
                long long sum = (long long)sortedNums[i] + (long long)sortedNums[j] + (long long)sortedNums[left] + (long long)sortedNums[right];
                if (sum == target) {
                    output.push_back({sortedNums[i], sortedNums[j], sortedNums[left], sortedNums[right]});
                    while (left < right && sortedNums[left] == sortedNums[left + 1])
                        left++;  // Skip duplicates
                    while (left < right && sortedNums[right] == sortedNums[right - 1])
                        right--; // Skip duplicates
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    
    return output;
}

};



