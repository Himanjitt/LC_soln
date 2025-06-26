class Solution {
public:
    int n;
    int solveForAlice(vector<int>&piles, int person,int i, int M, vector<vector<vector<int>>>&dp){
        if(i == piles.size()){
            return 0;
        }
        
        if(dp[person][i][M] != -1){
            return dp[person][i][M];
        }

        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;
        
        for(int x=1; x <= min(2*M, n-i); x++){
            stones += piles[i + x -1];

            if(person == 1){ //alice
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M,x), dp));
            }
            else{ //BOB
                result = min(result, solveForAlice(piles, 1, i+x, max(M, x), dp));
            }
        }

        return dp[person][i][M] = result;

    }
    int stoneGameII(vector<int>& piles) {
        if(piles.size() == 1) return piles[0];
         n = piles.size();
        //1 means alice , 0 means bob
        int M =1;
        vector<vector<vector<int>>>dp(2, vector<vector<int>>(n, vector<int>(n, -1)));
        return solveForAlice(piles, 1, 0, M, dp);
    }
};