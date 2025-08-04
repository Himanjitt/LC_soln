class Solution {
public:
    bool isValid(vector<int>& nums, int k, int maxSum) {
        int count = 1;
        int currentSum = 0;
        for (int num : nums) {
            currentSum += num;
            if (currentSum > maxSum) {
                count++;
                currentSum = num;
                if (count > k)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& a, int k) {
        int start = *max_element(a.begin(), a.end());
        int end = accumulate(a.begin(), a.end(), 0);
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(a, k, mid) == true) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};