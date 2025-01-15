class Solution {
public:
    bool solve(vector<int>& nums, int index, vector<int>&dp){
        if (index == nums.size() - 1) {
            return true;
        }
        if(dp[index]!=-1) 
            return dp[index];

        int n=nums.size();
        int end = min(index + nums[index], n - 1);

        for (int j = index+1; j <=end; j++) {
            if(solve(nums, j,dp)==true)
                return dp[j]=true;
        }

        return dp[index]=false;
    }

    bool canJump(vector<int>& nums) { 
        vector<int>dp(nums.size(),-1);
        return solve(nums, 0,dp); 
        }
};