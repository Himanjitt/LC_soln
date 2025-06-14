class Solution {
   public:
    bool solve(string &str, string &pat, int i, int j, vector<vector<int>>& dp) {
        // base Case
        if (i == str.size() && j == pat.size()) return true;  // both exhausted
        if (j == pat.size()) return false;  // pattern over, str not over
        if (i == str.size()) {
            // str over → remaining pattern must be all '*'
            for (int k = j; k < pat.size(); k++) {
                if (pat[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // both same
        if (str[i] == pat[j]) {
            bool bothSame = solve(str, pat, i + 1, j + 1, dp);
            return dp[i][j] = bothSame;
        }

        // both not same

        // case 1: both save different alphabets instead of special characters
        if (pat[j] != '?' && pat[j] != '*') {
            return false;
        }

        // case 2: if pat[j] == ? , definite answer return instantly
        if (pat[j] == '?') {
            return dp[i][j] = solve(str, pat, i + 1, j + 1, dp);
        }

        // case 3 : if pat[j] == *
        // case 3A: if str[i] is not empty
        int isNotEmpty = solve(str, pat, i + 1, j, dp);
        // case3B:if str[i] is empty
        int isEmpty = solve(str, pat, i, j + 1, dp);
        return dp[i][j] = isNotEmpty || isEmpty;
    }
    bool isMatch(string str, string pat) {
        int m = str.size();
        int n = pat.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(str, pat, 0, 0, dp);
    }
};
