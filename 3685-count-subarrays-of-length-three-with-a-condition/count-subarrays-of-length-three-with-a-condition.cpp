class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for(int i = 0; i <= n - 3; i++) {
            if(nums[i+1] % 2 == 0) { // check if divisible by 2
                if(nums[i] + nums[i+2] == nums[i+1]/2) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
