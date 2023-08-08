//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    
    int HCF(int a,int b)
    {
        int num1 = max(a,b);
        int num2 = min(a,b);
      
        while(num1%num2 != 0)
        {
            
            int rem = num1%num2;
            num1 = num2;
            num2 = rem;
            
        }
       
       return num2;
       
    }
   int countFractions(int n, int numerator[], int denominator[])
    {
        int pairs=0;
        
     
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++){
            int hcf=HCF(numerator[i],denominator[i]);
            int a=numerator[i]/hcf;
            int b=denominator[i]/hcf;
            if(mp.find({b-a,b})!=mp.end()){
                pairs+=mp[{b-a,b}];
            }
            mp[{a,b}]++;
                
           
        }
        return pairs;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends