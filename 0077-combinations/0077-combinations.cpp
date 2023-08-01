class Solution {
public:
    
    void solve(int i,int n,int k,vector<int>&ds,vector<vector<int>>&ans){
            if(ds.size()==k){
                ans.push_back(ds);
                return;
            }
//         ds.push_back(i);
//         solve(i+1,n,k,ds,ans);
//         ds.pop_back();
//         solve(i+1,n,k,ds,ans);
        
         for (int j = i; j <= n; j++) {
            ds.push_back(j);
            solve(j+1, n, k, ds, ans);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,n,k,ds,ans);
        return ans;
        
    }
};

