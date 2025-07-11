class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            else if (nums[start] <= nums[mid]) {
                // left side sorted
                if (nums[start] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } 
            else {
                // right side sorted
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } 
                else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};