class Solution {
public:
    void find(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        //Pick Up the element
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            find(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        //Not pick
        find(ind+1,target,arr,ans,ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        find(0,target,candidates,ans,temp);
        return ans;
    }
};