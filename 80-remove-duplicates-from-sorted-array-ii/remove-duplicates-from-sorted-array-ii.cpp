/*

    l
0,0,1,1,2,1,2,3,3
    r

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();

        while (right < n) {

            int count = 1;
            while (right + 1 < n && nums[right] == nums[right + 1]) {
                right++;
                count++;
            }

            for (int i = 0; i < min(2, count); i++) {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }

        return left;
    }
};