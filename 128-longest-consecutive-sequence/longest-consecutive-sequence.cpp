class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int maxlength = 1;
        int length = 1;
        // for(auto ele: nums){
        //     cout<<ele<<" ";
        // }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i + 1] - nums[i] == 1) {
                length++;
                maxlength = max(maxlength, length);
            } else {
                length = 1;
            }
        }
        return maxlength;
    }
};