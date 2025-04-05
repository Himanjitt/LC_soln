class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r=mat.size();
        int c=mat[0].size();

        int row=0, col=c-1;

        while(row<r && col>=0){
          if(mat[row][col]==target){
            return true;
          }
          else if(mat[row][col]<target){
            row++;
          }
          else{
            col--;
          }
        }
        return false;
    }
};