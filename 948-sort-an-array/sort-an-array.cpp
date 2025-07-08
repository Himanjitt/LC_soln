// merge sort
/*

    [5,2,4,3,1]
[2,5]        [1,3]

*/
class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end) {
        int left = start, right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= end) {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=0;i<temp.size();i++){
            nums[start + i] = temp[i];
        }
    }
    void divide(vector<int>& nums, int start, int end) {
        if (start == end) {
            return;
        }
        int mid = start + (end - start) / 2;

        divide(nums, start, mid);
        divide(nums, mid + 1, end);

        merge(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        divide(nums, 0, n - 1);
        return nums;
    }
};