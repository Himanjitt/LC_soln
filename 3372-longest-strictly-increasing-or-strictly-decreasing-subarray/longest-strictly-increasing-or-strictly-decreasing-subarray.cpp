class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxInc = 1, maxDec = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int countInc = 1, countDec = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[j - 1]) {
                    countInc++;
                    maxInc = max(maxInc, countInc);
                    countDec = 1; 
                } else if (nums[j] < nums[j - 1]) {
                    countDec++;
                    maxDec = max(maxDec, countDec);
                    countInc = 1; 
                } else {
                    break; 
                }
            }
        }

        return max(maxInc, maxDec);
    }
};