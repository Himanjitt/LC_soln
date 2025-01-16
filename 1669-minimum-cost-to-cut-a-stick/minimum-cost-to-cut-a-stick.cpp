class Solution {
public:
    int solve(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            int costs = cuts[j + 1] - cuts[i - 1] + solve(cuts, i, ind - 1,dp) +
                        solve(cuts, ind + 1, j,dp);

            ans = min(ans, costs);
        }

        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return solve(cuts, 1, c, dp);
    }
};