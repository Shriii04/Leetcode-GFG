class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;
        vector<int> ans;
        map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        
        for(auto x:m){
            if(x.second>n){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};