class Solution {
public:
    void helper(int idx, vector<int>& candidates, int n, int sum, int target, vector<int>& temp,         vector<vector<int>>& ans) {
        if (idx == n) {
            if (sum == target)
                ans.push_back(temp);
            return;
        }
        if ((sum + candidates[idx]) <= target) {
            sum += candidates[idx];
            temp.push_back(candidates[idx]);
            helper(idx, candidates, n, sum, target, temp, ans);
            sum -= candidates[idx];
            temp.pop_back();
        }
        helper(idx+1, candidates, n, sum, target, temp, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, candidates, n, 0, target, temp, ans);
        return ans;
    }
};