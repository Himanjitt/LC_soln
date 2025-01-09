class Solution {
public:
    int m,n;
    typedef pair<int,int> p;

    vector<p>movements={{1,0},{-1,0},{0,-1},{0,1}};

    bool isValid(int adj_x,int adj_y,vector<vector<int>>& isWater){
        if(adj_x < 0 || adj_x >=m || adj_y < 0 || adj_y >= n){
            return false;
        }

        return true;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m=isWater.size();
        n=isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));

        queue<p>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto a= q.front();
            q.pop();

            for(p movement: movements){
                int adj_x = a.first  + movement.first;
                int adj_y = a.second + movement.second;

                if(isValid(adj_x,adj_y,isWater)){

                    if(ans[adj_x][adj_y]==-1){
                        ans[adj_x][adj_y]= ans[a.first][a.second]+1;
                        q.push({adj_x,adj_y});
                    }
                }
            }
        }

        return ans;
    }
};