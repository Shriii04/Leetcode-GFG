//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
   
   bool neg = false;
   if(s1[0]=='-'){
       neg = !neg;
       s1 = s1.substr(1);
   }
   if(s2[0]=='-'){
       neg = !neg;
       s2 = s2.substr(1);
   }
   
   int cnt1, cnt2;
   for(cnt1=0; s1[cnt1]=='0'; cnt1++);
   for(cnt2=0; s2[cnt2]=='0'; cnt2++);
   s1 = s1.substr(cnt1);
   s2 = s2.substr(cnt2);
   
   if(s1.empty() || s2.empty()) return "0"; 
   
   string ans="";
   int len1=s1.length(), len2=s2.length();
   
   for(int i = len1-1; i >= 0; i--){
       
       int ansidx=ans.length()-len1+i, k=len2-1, carry=0;
       
       for(;ansidx>=0 && k>=0; k--, ansidx--){
           int n1 = s1[i]-'0';
           int n2 = s2[k]-'0';
           int n3 = ans[ansidx]-'0';
           int n4 = n1*n2 + n3 + carry;
           ans[ansidx] = '0' + n4%10;
           carry = n4/10;
       }
       for(; k >= 0; k--){
          int n1 = s1[i]-'0';
          int n2 = s2[k]-'0';
          int n3 = n1*n2 + carry;
          ans = ((char)('0' + n3%10)) + ans;
          carry = n3/10;
       }
       if(carry) ans = ((char)('0'+carry)) + ans;
   }
   
   if(neg) return ('-'+ans);
   return ans;
   
}

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends