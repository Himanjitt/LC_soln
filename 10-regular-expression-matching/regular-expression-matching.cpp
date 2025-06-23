class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>>&dp){
        if(j == p.size()){
            //both should end at same time
            if(i == s.size()){
                return true;
            }
            return false;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(p[j+1] == '*'){
            //not take
            bool notTake = solve(s, p, i, j+2, dp);
            //take
            bool take = false;
            if((i < s.size()) && (s[i] == p[j] || p[j] == '.')){
                take = solve(s, p, i+1, j, dp);
            }

            return dp[i][j] = notTake || take;
        }

        //else means normal case
        bool elseOP = false;
        if((i < s.size()) && (s[i] == p[j] || p[j] == '.')){
            elseOP = solve(s, p, i+1, j+1, dp);
        }
        return dp[i][j] =  elseOP;
    }


    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s, p, 0, 0, dp);
    }
};