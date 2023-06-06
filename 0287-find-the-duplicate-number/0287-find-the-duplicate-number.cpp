class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto x:nums){
            m[x]++;
        }
        for(auto x:nums){
            if(m[x]!=1){
                return x;
            }
        }
        return 0;
    }
};