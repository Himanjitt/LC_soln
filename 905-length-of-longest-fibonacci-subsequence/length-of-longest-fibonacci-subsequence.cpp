class Solution {
public:
    int lenLongestFibSubseq(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
            mpp[nums[i]] = i;
        unordered_map<int,unordered_map<int,int>> dp;
        int res = 0;

        for (int j = 1; j < nums.size(); j++) {
            for (int i = 0; i < j; i++) {
                if (mpp.find(nums[j] - nums[i]) != mpp.end() && mpp[nums[j] - nums[i]] < i) {
                    dp[i][j] = dp[mpp[nums[j] - nums[i]]][i] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res > 0 ? res + 2 : 0;  
    }
};