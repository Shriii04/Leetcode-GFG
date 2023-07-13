class Solution {
public:
     void find(int ind,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
           
        ans.push_back(ds);
            
        //Pick Up the element
        for(int i=ind;i<arr.size();i++){
            
            //if(i>ind && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            find(i+1,arr,ans,ds);
            ds.pop_back();
        }
         
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        find(0,nums,ans,temp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};