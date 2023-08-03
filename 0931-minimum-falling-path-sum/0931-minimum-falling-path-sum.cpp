// class Solution {
// public:
//     int solve(int i,int j,vector<vector<int>> &a,vector<vector<int>> &dp){        
//         if(j<0 || j>a[0].size()-1) return 1E9;
//         if(i==0) return a[i][j];
//         if(dp[i][j] != -1) return dp[i][j];
//         int up = a[i][j] + solve(i-1,j,a,dp);
//         int left = a[i][j] + solve(i-1,j-1,a,dp);
//         int right = a[i][j] + solve(i-1,j+1,a,dp);
//         return dp[i][j] = min(up,min(left,right));
        
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix[0].size();
//         int n = matrix.size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         int ans = INT_MAX;
//         for(int j=0;j<m;j++){
//             ans = min(ans,solve(n-1,j,matrix,dp));
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>>dp; //our programs brain; currently empty 
    int util(vector<vector<int>>& arr, int i, int j){
        if(i>=arr.size()){
            return 0;
        }//base case when we go out of the matrix
        if(dp[i][j]!= 100000)return dp[i][j]; //if we already found our answer and stored in our brain then return that answer no need to make further recursive calls.
        int ans=INT_MAX;
        if(j==0){// if j==0 =>that we can go to j, j+1th element of next row
            int a= arr[i][j]+util(arr, i+1, j);
            int b= INT_MAX;
            //although there can be case where we have only 1 col
            //edge case
            if(j+1<arr[0].size()) b=arr[i][j]+ util(arr, i+1, j+1);
            ans= min({a, b, ans});
        }
        else if(j==arr[0].size()-1){//if j==arr[0].size()=> we are at last column and
        //we can make only call to j, j-1th element in next row
            int a= arr[i][j]+util(arr, i+1, j);
            int b= INT_MAX;
            //edge case when we have only one col in matrix
            if(j-1>=0)b= arr[i][j]+util(arr, i+1, j-1);
            ans=min({a, b, ans});
        }else{//this case is when we not the first col, last col we are in the cols between them 
        //so we have 3 cases as mentioned in the problem
            //three cases are as follows:
            //1) add me and go to next ele below me.
            //2) add me and go to diagonally left ele below me.
            //3) add me and go to diagonally right ele below me.
            int a= arr[i][j]+util(arr, i+1, j);
            int b= arr[i][j]+util(arr, i+1, j-1);
            int c= arr[i][j]+util(arr, i+1, j+1);
            ans= min({a, b, c, ans});
        }
        return dp[i][j]= ans;// store calculated result into the brain
        //so that i can easilly return calculated result without doing calculations repeatatively.

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        dp.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 100000));//defining our brain size.
        //for the first row only we have any choice to choose our
        //starting point.
        //but ater that we have at max 3 choices only 
        for(int j=0; j<matrix[0].size(); j++){
            int curr= util(matrix, 0, j);
            ans= min(ans, curr);
        }
        return ans;
    }
};