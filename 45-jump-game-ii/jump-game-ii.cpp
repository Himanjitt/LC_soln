class Solution {
public:
 int solve(vector<int>& nums, int index,vector<int>&dp){
        if (index == nums.size() - 1) {
            return 0;
        }
        if(dp[index]!=-1)
            return dp[index];

        int min_jumps=INT_MAX;
        int n=nums.size();
        int end = min(index + nums[index], n - 1);

        for (int j = index+1; j <=end; j++) {
            int jumps = solve(nums, j,dp);
            if (jumps != INT_MAX) {
                min_jumps = min(min_jumps, 1 + jumps);
            }
        }

        return dp[index]=min_jumps;
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        
        return solve(nums, 0,dp); 
    }
};
