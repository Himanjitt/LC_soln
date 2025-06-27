class Solution {
public:
    int solve(int i, int j, vector<int>&piles, vector<vector<int>>&dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //alice picks starting - bob pick rest
        int startPick = piles[i] - solve(i+1, j, piles, dp);

        //alice picks ending - bob pick rest
        int endPick = piles[j] - solve(i, j-1, piles, dp);

        return dp[i][j] = max(startPick, endPick);

    }
    bool predictTheWinner(vector<int>& piles) {
        //substract alice score - lee score
        int n= piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int diff = solve(0, n-1, piles, dp);
        if(diff >= 0) return true;

        return false;
        
    }
};