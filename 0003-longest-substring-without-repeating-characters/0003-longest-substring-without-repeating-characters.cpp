class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        int ans = INT_MIN;
        unordered_set<int> s1;
        int l=0;
        for(int r=0;r<s.size();r++){
            if(s1.find(s[r])!=s1.end()){
                while(l<r && s1.find(s[r])!=s1.end() ){
                    s1.erase(s[l]);
                    l++;
                }
            }
            s1.insert(s[r]);
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};