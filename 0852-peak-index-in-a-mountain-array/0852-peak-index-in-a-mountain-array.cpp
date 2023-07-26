class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for(int i=1;i<arr.size();i++){
            if(arr.size()>=3){
                if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                return i;
            }
            }
        }
        return -1;
    }
};