class Solution {
public:
    int m, n, p;
    int dp[101][101][201];

    bool solve(int i, int j, int k, string& s1, string& s2, string& s3) {
        if (i == m && j == n && k == p) {
            return true;
        }

        if (k >= p) {
            return false;
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        // case1
        bool ans = false;
        if (s1[i] == s3[k]) {
            ans = solve(i + 1, j, k + 1, s1, s2, s3);
        }

        //pre check
        if(ans == true){
            return true;
        }

        //case2
        if (s2[j] == s3[k]) {
            ans = solve(i, j + 1, k + 1, s1, s2, s3);
        }

        return dp[i][j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size();
        n = s2.size();
        p = s3.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, s1, s2, s3);
    }
};