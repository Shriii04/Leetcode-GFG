class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int ans=0;
        unordered_map<char,int> mp;
        int maxcount=0;
        for(int j=0;j<s.size();j++){
            mp[s[j]]++;
            maxcount = max(maxcount,mp[s[j]]);
            if(j-i+1-maxcount>k){
                mp[s[i]]--;
                i++;
            }
            else{
                ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};