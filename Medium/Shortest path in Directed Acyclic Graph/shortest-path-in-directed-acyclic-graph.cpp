//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
         vector<int> dist(N, INT_MAX);
        vector<bool> vis(N, false);
        queue<int> w;
    
        dist[0] = 0;
        w.push(0);
    
        while (!w.empty()) {
            int curr = w.front();
            w.pop();
            vis[curr] = true;
    
            for (auto x : edges) {
                if (x[0] == curr) {
                    if (dist[x[1]] > dist[curr] + x[2]) {
                        dist[x[1]] = dist[curr] + x[2];
                        w.push(x[1]);
                    }
                }
            }
        }
    
        for (int& x : dist) {
            if (x == INT_MAX) {
                x = -1;
            }
        }
    
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends