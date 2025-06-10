class Solution {
public:
    int solve(vector<vector<int>>& nums, int ind, int prevInd, vector<vector<int>> &dp) {
        // pruning

        // base case
        if (ind == nums.size()) {
            return 0;
        }
        //to normalize since prevInd can be -1
        if(dp[ind][prevInd + 1] != -1){
            return dp[ind][prevInd + 1];
        }
        // choices  
        // not take
        int notTake = solve(nums, ind + 1, prevInd, dp);

        // take
        int take = 0;
        if ((prevInd == -1) || nums[ind][0] > nums[prevInd][1]) {
            take = 1 + solve(nums, ind + 1, ind, dp);
        }
        return dp[ind][prevInd + 1] = max(notTake, take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(pairs, 0, -1, dp);
    }
};