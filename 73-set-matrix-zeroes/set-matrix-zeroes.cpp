class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> col(n, 1);  // Initialize columns to 1
        vector<int> row(m, 1);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    col[j]=0;
                    row[i]=0;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(col[j]==0 || row[i]==0 ){
                    matrix[i][j]=0;
                }
                
            }
        }
        
    }
};