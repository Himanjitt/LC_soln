class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LISdp(n, 1);
        vector<int> count(n, 1);

        int maxLIS = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (LISdp[i] == LISdp[j] + 1) {
                        count[i] = count[i] + count[j];
                    } else if (LISdp[i] < LISdp[j] + 1) {
                        LISdp[i] = LISdp[j] + 1;
                        count[i] = count[j];
                    }
                    maxLIS = max(maxLIS, LISdp[i]);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (LISdp[i] == maxLIS) {
                ans += count[i];
            }
        }

        return ans;
    }
};