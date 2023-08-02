//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// class Solution {
// public:
//     int shortestDistance(int N, int M, vector<vector<int>>& A, int X, int Y) {
//         vector<vector<int>> dp(N, vector<int>(M, INT_MAX - N * M));

//         if (A[0][0] == 0 || A[X][Y] == 0) {
//             return -1;  // Either start or destination is not reachable
//         }

//         dp[0][0] = 0;

//         for (int i = 0; i < N; ++i) {
//             for (int j = 0; j < M; ++j) {
//                 if (A[i][j] == 1) {
//                     if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
//                     if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
//                 }
//             }
//         }

//         if (dp[X][Y] == INT_MAX - N * M) {
//             return -1;  // Destination is not reachable
//         }

//         return dp[X][Y];
//     }
// };

class Solution {

  public:

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});

        vector<vector<int>> vis(N, vector<int>(M, 0));

        vis[0][0]=1;

        int di[]={0, -1, 0, 1};

        int dj[]={-1, 0, 1, 0};

        while(!pq.empty()){

            int steps = pq.top().first;

            int x = pq.top().second.first;

            int y = pq.top().second.second;

            pq.pop();

            

            if(x==X && y==Y){

                return steps;

            }

            

            for(int i=0;i<4;i++){

                int dx = x + di[i];

                int dy = y + dj[i];

                

                if(dx>=0 && dx<N && dy>=0 && dy<M && A[dx][dy]==1 && vis[dx][dy]==0){

                    vis[dx][dy]=1;

                    pq.push({steps+1,{dx, dy}});

                }

            }

            

        }

        return -1;

    }

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends