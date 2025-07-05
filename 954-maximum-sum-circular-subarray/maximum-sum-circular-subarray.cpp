class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
    int minSubArray(vector<int>nums){
        int sum = 0, mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum = min(nums[i], sum + nums[i]);
            mini = min(mini, sum);
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(),0);

        int maxSub = maxSubArray(nums);
        int minSub = minSubArray(nums);

        if (maxSub < 0) return maxSub;

        return max(maxSub ,totalSum - minSub);
    }
};