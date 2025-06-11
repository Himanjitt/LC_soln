class Solution {
   public:
    int solve(string &str1, string &str2, int i, int j,
              vector<vector<int>> &dp) {
        if (i == str1.size() || j == str2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // both have same
        int bothSame = 0;
        if (str1[i] == str2[j]) {
            bothSame = 1 + solve(str1, str2, i + 1, j + 1, dp);
        }

        // both not same

        // i move forward
        int iMove = solve(str1, str2, i + 1, j, dp);

        // j move forward
        int jMove = solve(str1, str2, i, j + 1, dp);
        
        //change here in maxi
        return dp[i][j] = max({bothSame, iMove, jMove});

    }
    int longestCommonSubsequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(str1, str2, 0, 0, dp);
    }
};
