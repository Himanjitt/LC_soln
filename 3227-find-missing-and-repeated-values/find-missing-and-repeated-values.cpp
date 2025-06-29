class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans(2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[nums[i][j]]++;
                if (mp[nums[i][j]] == 2) {
                    ans[0] = nums[i][j];
                }
            }
        }
        for (int i = 1; i <= n * n; i++) {
            if (mp.find(i) == mp.end()) {
                ans[1] = i;
            }
        }

        return ans;
    }
};