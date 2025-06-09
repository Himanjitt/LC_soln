class Solution {
public:
    long long solve(vector<int>& nums, int ind, bool isEven, vector<vector<long long>>&dp) {
        if (ind == nums.size()) {
            return 0;
        }

        if(dp[ind][isEven] != -1){
            return dp[ind][isEven];
        }
        //not take
        long long notTake = solve(nums, ind+1, isEven, dp);

        //take
        long long take=0;
        if(isEven){
            take = nums[ind] + solve(nums, ind + 1, false,dp);
        }
        else{
            take = -nums[ind] + solve(nums, ind + 1, true,dp);
        }

        
        return dp[ind][isEven]=max(take , notTake);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return solve(nums, 0, true, dp);
    }
};