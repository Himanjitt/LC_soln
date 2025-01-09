class Solution {
public:
    int m,n;

    void dfs(int i, int j, bool &check,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==1 || grid[i][j]==-1){
                return;
            }
        grid[i][j]=-1;

        if (i == 0 || i == m-1 || j == 0 || j == n-1) {
            check = true;
        }
        dfs(i+1,j,check,grid);
        dfs(i-1,j,check,grid);
        dfs(i,j+1,check,grid);
        dfs(i,j-1,check,grid);
    }

    int closedIsland(vector<vector<int>>& grid) {    
        m=grid.size();
        n=grid[0].size();

        int count=0;

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    bool check=0;
                    dfs(i,j,check,grid);
                    if(check==0)
                        count++;
                }
            }
        }

        return count;
    }
};

