class Solution {
public:
    int totalSumOffset;
    int solve(int target, vector<int>& nums, int currSum, int ind,
              vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            if (currSum == target) {
                return 1;
            }
            return 0;
        }
        //normalizing the sum for valid access in dp table
        //to avoid -ve index 
        int normalizedSum = currSum + totalSumOffset;

        if (dp[ind][normalizedSum] != -1) {
            return dp[ind][normalizedSum];
        }

        // take -
        int left = solve(target, nums, currSum - nums[ind], ind + 1, dp);

        // take +
        int right = solve(target, nums, currSum + nums[ind], ind + 1, dp);

        return dp[ind][normalizedSum] = left + right;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int currSum = 0;
        int n = nums.size();
        // saving states of index and currSum;
        // note that here the sum can go negative which cannot be
        // stored in dp table directly, therefore we normalize it
        // by using offset here ie the totalsum [-x,0] to [0,x];
        totalSumOffset = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n + 1, vector<int>(2 * totalSumOffset + 1, -1));
        return solve(target, nums, currSum, 0, dp);
    }
};