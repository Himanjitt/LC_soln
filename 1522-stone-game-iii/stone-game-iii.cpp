class Solution {
public:
    int n;
    int solveForAlice(vector<int>&piles,int person, int i, vector<vector<int>>&dp){
        if(i == piles.size()){
            return 0;
        }
        if(dp[person][i] != -1){
            return dp[person][i];
        }

        int result = (person == 1) ? INT_MIN : INT_MAX;
        int stones = 0;
        
        for(int x=1; x <= 3; x++){
            if(i + x -1 >= n) continue;
            stones += piles[i + x -1];

            if(person == 1){ //alice
                result = max(result, stones + solveForAlice(piles, 0, i+x, dp));
            }
            else{ //BOB
                result = min(result, solveForAlice(piles, 1, i+x, dp));
            }
        }

        return  dp[person][i] = result;

    }
    string stoneGameIII(vector<int>& piles) {
        if(piles.size() == 1) {
            if(piles[0] > 0)
                return "Alice";

            return "Bob";
        }
        n = piles.size();
        //1 means alice , 0 means bob
        int sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>>dp(2,vector<int>(n,-1));
        int AliceScore = solveForAlice(piles, 1, 0, dp);
        int BobScore = sum - AliceScore;

        if(BobScore == AliceScore) return "Tie";
        if(BobScore > AliceScore) return "Bob";
        return "Alice";
    }
};