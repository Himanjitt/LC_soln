class Solution {
public:
    unordered_set<string> st;
    bool solve(string& s, int i, vector<int>&dp) {
        if (i == s.size()) {
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        for (int l = 1; l <= s.size(); l++) {
            string temp = "";
            temp = s.substr(i, l);

            if (st.count(temp) && solve(s, i + l, dp) == true) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for (auto ele : wordDict) {
            st.insert(ele);
        }
        vector<int>dp(n, -1);
        return solve(s, 0, dp);
    }
};