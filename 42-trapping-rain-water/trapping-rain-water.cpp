class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        vector<int> prefixMax(n), suffixMax(n);

        prefixMax[0] = height[0];
        suffixMax[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            ans += min(leftMax, rightMax) - height[i];
        }
        return ans;
    }
};