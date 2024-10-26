class Solution {
public:
    int solve(int m,int n, vector<vector<int>>& grid, int i, int j,int nonObstacle,int count){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1 ){
                return 0;
            }
         if (grid[i][j] == 2) {
            return count == nonObstacle ? 1 : 0;
        }
        
        int temp = grid[i][j];
        grid[i][j] = -1;
        int up=solve(m,n,grid,i+1,j,nonObstacle,count+1);
        int down=solve(m,n,grid,i-1,j,nonObstacle,count+1);
        int left=solve(m,n,grid,i,j-1,nonObstacle,count+1);
        int right=solve(m,n,grid,i,j+1,nonObstacle,count+1);
        grid[i][j] = temp;

        return up+down+left+right;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int nonObstacle=1;
        int startRow=0,startCol=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 ||grid[i][j]==2){
                    nonObstacle++;
                }
                if(grid[i][j]==1){
                    startRow=i;
                    startCol=j;
                }
            }
        }
        int count=1;
        return solve(m,n,grid,startRow,startCol,nonObstacle,count);
    }
};