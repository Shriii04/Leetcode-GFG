class Solution {
public:

     void solve(vector<int>& nums, set<vector<int>>& s, vector<int> temp, int index){
        if(index == nums.size()){
            s.insert(temp);
            return;
        }
        for(int i=index; i<temp.size(); i++){
            swap(temp[index], temp[i]);
            solve(nums, s, temp, index+1);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        set<vector<int>> s;
        solve(nums, s, temp, 0);
        for(auto it : s){
            output.push_back(it);
        }
        return output;
    }
};