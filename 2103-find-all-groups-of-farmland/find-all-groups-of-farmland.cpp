class Solution {
public:
    vector<vector<int>> ans;
    int m, n;
    void dfs(int i, int j, vector<vector<int>>& land, int &min_x,
            int &min_y,int &max_x,int &max_y) {
        if (i < 0 || i >= m || j < 0 || j >= n || land[i][j] == -1 || land[i][j]==0) {
            return;
        }
        land[i][j] = -1;

        min_x = min(min_x, i);
        min_y = min(min_y, j);
        max_x = max(max_x, i);
        max_y = max(max_y, j);

        dfs(i - 1, j, land,min_x,min_y,max_x,max_y);
        dfs(i + 1, j, land,min_x,min_y,max_x,max_y);
        dfs(i, j + 1, land,min_x,min_y,max_x,max_y);
        dfs(i, j - 1, land,min_x,min_y,max_x,max_y);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int min_x = i, min_y = j, max_x = i, max_y = j;
                    dfs(i, j, land, min_x, min_y, max_x, max_y);
                    ans.push_back({min_x, min_y, max_x, max_y});
                }
            }
        }

        return ans;
    }
};