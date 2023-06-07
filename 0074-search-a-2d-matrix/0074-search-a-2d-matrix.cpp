class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
         int n=arr.size();
        int m=arr[0].size();
        int i=0;
        
        while(i<n)
        {
        if(target<=arr[i][m-1])
        {
            int j=0;
            while(j<m)
            {
                if(target==arr[i][j])
                return true;
                else if(target<arr[i][j])
                return false;
                else
                j++;
            }
            return false;
        }
        i++;
        }
               
    return false;
    }
};