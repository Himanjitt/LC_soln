class Solution {
public:
    bool isValid(string& temp) {
        if (temp[0] == '0') {
            return false;
        }
        int num = stoi(temp);
        if (num >= 1 && num <= 26) {
            return true;
        }

        return false;
    }
    int solve(string& s, int i, vector<int>& dp) {
        // base case
        if (i == s.size()) {
            return 1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int count = 0;
        //we have two options only , take 1 or take till 2
        //could have done in 2 recursive calls, here in partition dp form
        for (int k = 1; k <= 2; k++) {
            string temp = "";
            if (i + k <= s.size()) {
                temp = s.substr(i, k);

                if (isValid(temp) == true) {
                    count += solve(s, i + k, dp);
                }
            }
        }

        return dp[i] = count;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, 0, dp);
    }
};