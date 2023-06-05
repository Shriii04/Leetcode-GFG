class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        vector <int> Row(nrow,-1);
        vector<int> Col(ncol,-1);
        for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
                if(matrix[i][j]==0){
                    Row[i] = 0;
                    Col[j] = 0;
                }
            }
        }
         for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
                if(Row[i] == 0 || Col[j] == 0 ){
                    matrix[i][j]=0;
                }
            }
        }
    }
};