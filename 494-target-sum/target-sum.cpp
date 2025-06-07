class Solution {
public:
    int solve(int target, vector<int>&nums, int currSum, int ind){
        if(ind == nums.size()){
            if(currSum == target){
                return 1;
            }
            return 0;
        }

        //take -
        int left = solve(target, nums, currSum - nums[ind], ind+1);

        //take +
        int right = solve(target, nums, currSum + nums[ind], ind+1);

        return left + right;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int currSum=0;
        return solve(target, nums, currSum, 0);
    }
};