class Solution {
  public:
    int solve(string &start, string &target, int i, int j, vector<vector<int>>&dp){
        //base case very tricky
        // if len of start is small and len of target is big
        if(i == start.size()){
            return target.size() - j;
        }
        // if len of start is big and len of target is small
        if(j == target.size()){
            return start.size() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //both same
        int bothSame=0;
        if(start[i] == target[j]){
             bothSame = solve(start, target, i+1, j+1, dp);
             return dp[i][j]=bothSame;
        }

        //both not same
        int insert = 1 + solve(start, target, i, j+1, dp);
        int deleted = 1 + solve(start, target, i+1, j, dp);
        int replace = 1+ solve(start, target, i+1, j+1, dp);
        
        return dp[i][j] = min({insert, deleted, replace});
    }
    int minDistance(string start, string target) {
        int m=start.size(), n=target.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(start, target, 0 , 0, dp);
    }
};

