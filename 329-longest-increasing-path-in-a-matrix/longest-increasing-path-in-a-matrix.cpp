class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& mat,
              vector<vector<int>>& dp) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int maxim = 0;

        for (auto dir : dirs) {

            int drow = dir[0] + row;
            int dcol = dir[1] + col;

            if (drow >= 0 && dcol >= 0 && drow < n && dcol < m &&
                mat[drow][dcol] > mat[row][col]) {
                maxim = max(maxim, 1 + solve(drow, dcol, mat, dp));
            }
        }
        return dp[row][col] = maxim;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, matrix, dp));
            }
        }
        return ans + 1;
    }
};