//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    vector<int> generateNextPalindrome(int num[], int n)
    {
        int change = 0;
        bool flag = false, f1 = false;
        vector<int> ans(n);
        int po = INT_MAX , ne = INT_MAX;
        for (int i = 0; i < n / 2 + n % 2; i++)
        {
            if (num[i] != num[n - i - 1])
            {
                change = num[i] - num[n - i - 1];
                if (change > 0)
                    po = n - 1 - i;
                if (change < 0)
                    ne = n - i - 1;
                f1 = true;
                ans[i] = num[i];
                ans[n - 1 - i] = num[i];
            }
            else
            {
                ans[i] = num[i];
                ans[n - 1 - i] = num[n - 1 - i];
            }
        }
        if (po < ne)
        {
            return ans;
        }
        else
        {
            if ((n & 1))
            {
                if (ans[n / 2] < 9)
                {
                    ans[n / 2]++;
                    return ans;
                }
                else
                {
                    int index = n / 2;
                    while (index >= 0 && ans[index] == 9)
                    {
                        ans[index] = 0;
                        ans[n - index - 1] = 0;
                        index--;
                    }
                    if (index < 0)
                    {
                        ans.insert(ans.begin(), 1);
                        ans[n] = 1;
                    }
                    else
                    {
                        ans[index]++;
                        ans[n - index - 1]++;
                    }
                    return ans;
                }
            }
            else
            {

                if (ans[(n / 2) - 1] < 9)
                {
                    ans[n / 2]++;
                    ans[(n / 2) - 1]++;
                    return ans;
                }
                else
                {
                    int index = (n / 2) - 1;
                    while (index >= 0 && ans[index] == 9)
                    {
                        ans[index] = 0;
                        ans[n - index - 1] = 0;
                        index--;
                    }
                    if (index < 0)
                    {
                        ans.insert(ans.begin(), 1);
                        ans[n] = 1;
                    }
                    else
                    {
                        ans[index]++;
                        ans[n - index - 1]++;
                    }
                    return ans;
                }
            }
        }
    }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends