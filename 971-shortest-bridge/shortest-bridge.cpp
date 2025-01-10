class Solution {
public:
    int n;

    bool isValid(int i, int j){
        if(i<0 || i>=n || j<0 || j>=n){
            return false;
        }
        return true;
    }

    void dfs(vector<vector<int>>& grid, int i , int j, queue<pair<int,int>>&q){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]==-1 || grid[i][j]==0){
            return;
        }
        q.push({i,j});
        grid[i][j]=-1;

        dfs(grid, i+1, j, q);
        dfs(grid, i-1, j, q);
        dfs(grid, i, j+1, q);
        dfs(grid, i, j-1, q);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        queue<pair<int,int>>q;
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    flag=1;
                    dfs(grid,i,j,q);
                    break;
                }
            }
            if(flag==1)
                break;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }


        vector<pair<int,int>> movements={
                    {1,0},
                {0,-1},   {0,1},
                    {-1,0}    
        };
        int level=0;

        while(!q.empty()){
            int size=q.size();

            level++;
            while(size--){
                pair<int,int> a=q.front();
                q.pop();

                for(auto movement: movements){
                    int adj_x = a.first  + movement.first;
                    int adj_y = a.second + movement.second;

                    if(isValid(adj_x,adj_y)==true && grid[adj_x][adj_y]==1){
                        return level-1;
                    }
                    if(isValid(adj_x,adj_y)==true && grid[adj_x][adj_y]==0){
                        grid[adj_x][adj_y]=-1;
                        q.push({adj_x,adj_y});
                    }
                }
            }
        }

        return -1;
    }
};