class Solution {
public:
    string check(string s,int left,int right){
    int n=s.length();
    while(left>=0 && right<n){
        if(s[left]!=s[right]) break; 
        left--; right++;
    }
    return s.substr(left+1,right-left-1);
}
    string longestPalindrome(string s) {
            string longest;
    int n=s.size();
    for(int i=0;i<n;i++){
        string odd=check(s,i,i);
        if(odd.size()>longest.size()) longest=odd;
    }
    for(int i=0;i<n;i++){
        string even=check(s,i,i+1);
        if(even.size()>longest.size()) longest=even;
    }
    return longest;
    }
    
    
};