class Solution {
public:
    void solve(vector<int> &nums, int target, int sum, int &count,int index) {

        if (index == nums.size()) {
            if (sum == target) {
                count++;
            }
            return;
        }

        solve(nums, target, sum + nums[index], count, index + 1);
        solve(nums, target, sum - nums[index], count, index + 1);

    }

    int findTargetSumWays(vector<int>& nums, int target) {

        
        int count=0;
        solve(nums, target,0, count,0);

        return count;
    }
};