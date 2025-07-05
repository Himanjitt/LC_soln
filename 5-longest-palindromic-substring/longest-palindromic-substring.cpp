class Solution {
public:
    int start = 0, maxLength = 1;

    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int i, int j, const string& s, vector<vector<int>>& dp) {
        if (i > j)
            return;

        if (dp[i][j] != -1) // Already visited
            return;

        dp[i][j] = 1; // Mark as visited

        if (isPalindrome(s, i, j)) {
            if (j - i + 1 > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }

        solve(i + 1, j, s, dp);
        solve(i, j - 1, s, dp);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // memo table to track visited (i, j)
        solve(0, n - 1, s, dp);
        return s.substr(start, maxLength);
    }
};
