class Solution {
public:
    // int solve(vector<int>& piles, int i, vector<int>& dp) {
    //     if (i == piles.size())
    //         return 0;

    //     if (dp[i] != -1) {
    //         return dp[i];
    //     }

    //     int take1 = piles[i] - solve(piles, i + 1, dp);

    //     int take2 = INT_MIN;
    //     if (i + 1 < piles.size()) {
    //         take2 = piles[i] + piles[i + 1] - solve(piles, i + 2, dp);
    //     }

    //     int take3 = INT_MIN;
    //     if (i + 2 < piles.size()) {
    //         take3 = piles[i] + piles[i + 1] + piles[i + 2] -
    //                 solve(piles, i + 3, dp);
    //     }

    //     return dp[i] = max({take1, take2, take3});
    // }

    string stoneGameIII(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n + 1 , 0);
        // int diff = solve(piles, 0, dp);

        // base case
        //handled in vector declaration

        // iteration
        for (int i = n-1; i >=0; i--) {
            
            int take1 = piles[i] - dp[i + 1];

            int take2 = INT_MIN;
            if (i + 1 < piles.size()) {
                take2 = piles[i] + piles[i + 1] - dp[i + 2];
            }

            int take3 = INT_MIN;
            if (i + 2 < piles.size()) {
                take3 = piles[i] + piles[i + 1] + piles[i + 2] -
                        dp[i + 3];
            }

            dp[i] = max({take1, take2, take3});
        }

        int diff = dp[0];

        if (diff == 0)
            return "Tie";
        if (diff < 0)
            return "Bob";
        return "Alice";
    }
};