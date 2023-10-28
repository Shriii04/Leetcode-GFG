//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
int is_bleak(int n)
    {
        // see all the magic is in n - log2(n)
        // max set bits in any number <= n can be ceil value of log2(n), so the minimum i should be n-log2(n)  
        
        for (int i = n - 1; i >= n - ceil(log2(n)); i--)
        {
            if (i + __builtin_popcount(i) == n)
                return 0;
        }

        return 1;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends