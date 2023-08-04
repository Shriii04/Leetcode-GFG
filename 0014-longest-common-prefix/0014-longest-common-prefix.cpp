class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int s = strs.size();
        string start = strs[0];
        string end = strs[s-1];
        string ans ="";
        for(int i=0;i < min(start.size(),end.size());i++){
            if(start[i]!=end[i]){
                return ans;
            }
            else{
                ans+=start[i];
            }
        }
        return ans;
    }
};