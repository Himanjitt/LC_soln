class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minTillNow = INT_MAX;
        int maxDiff = INT_MIN; 
        for (int i = 0; i < n; i++) {
            minTillNow = min(minTillNow, nums[i]);
            if (nums[i] > minTillNow) {
                maxDiff = max(maxDiff, nums[i] - minTillNow);
            }
        }
        if (maxDiff == INT_MIN)
            return -1;
        return maxDiff;
    }
};

/*
 1 4 5 7

*/