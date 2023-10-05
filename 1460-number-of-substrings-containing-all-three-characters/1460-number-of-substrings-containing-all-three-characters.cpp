class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int ans=0;
        int n = s.size();
        unordered_map<char,int> mp;
        for(int j=0;j<s.size();j++){
            mp[s[j]]++;
            while(i<=j && mp.size()==3){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            ans += i;
        }
        return ans;
    }
};