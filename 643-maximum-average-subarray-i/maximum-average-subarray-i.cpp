class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int left = 0, right = 0;

        double sum = 0;
        while (right < n) {
            if (right - left + 1 > k) {
                sum -= nums[left];
                left++;
            }
            sum += nums[right];
            if(right-left+1==k)
                ans = max(ans, sum / k);
            right++;
        }
        return ans;
    }
};