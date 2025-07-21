
class Solution {
public:
    long long solve(vector<int>& nums, int i, bool isEven, vector<vector<long long>>&dp){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][isEven] != -1){
            return dp[i][isEven];
        }
        //not take
        long long notTake = solve(nums, i+1, isEven, dp);

        //take
        long long take = 0;
        //if even then add 
        if(isEven){
            take = nums[i] + solve(nums, i+1, false, dp);
        }else{
            take = -nums[i] + solve(nums, i+1, true, dp);
        }

        return dp[i][isEven] = max(notTake, take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        bool isEven = true;
        int n = nums.size();
        vector<vector<long long>>dp(n, vector<long long>(2, -1));
        return solve(nums, 0, isEven, dp);
    }   
};