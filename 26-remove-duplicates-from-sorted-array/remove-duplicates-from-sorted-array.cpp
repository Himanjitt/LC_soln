class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // left will store the unique elements only
        // right will find the unique elements and give it to left
        int left = 0, right = 1;
        int n = nums.size();
        while (right < n) {
            if(nums[right] != nums[left]){
                left++;
                nums[left]= nums[right];
            }
            right++;
        }

        return left+1;
    }
};