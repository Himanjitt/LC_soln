class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(); // Size of the array

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        // To store the index of last element in the LIS
        int lastIndex = 0;

        // To store the length of LIS
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int prevInd = 0; prevInd < i; prevInd++) {
                if (nums[i] % nums[prevInd] == 0) {
                    if (dp[i] < dp[prevInd] + 1) {
                        dp[i] = dp[prevInd] + 1;
                        parent[i] = prevInd;
                    }
                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        lastIndex = i;
                    }
                }
            }
        }
        vector<int> ans;

        while (lastIndex != -1) {
            ans.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }

        // Reverse to get the LIS
        reverse(ans.begin(), ans.end());

        return ans;
    }
};