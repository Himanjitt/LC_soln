class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        dp[0][0] = 0;
        dp[1][1] = 1;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if(j+1 <= n)
                    dp[i][j+1]= dp[i][j] + dp[i][j+1];
                if(i+1 <= m)    
                    dp[i+1][j]= dp[i][j] + dp[i+1][j];
            }
        }

        return dp[m][n];
    }
};