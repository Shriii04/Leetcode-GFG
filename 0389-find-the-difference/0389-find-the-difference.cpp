class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1=0,sum2=0;
        for(int i=0;i<s.size();i++){
            sum1+=s[i];            
        }
        for(int j=0;j<t.size();j++){
            sum2+=t[j];
        }
    return (char)(sum2-sum1);        
    }
};