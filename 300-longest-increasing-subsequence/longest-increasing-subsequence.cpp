class Solution {
   public:
    // int solve(vector<int>& nums, int ind, int prevInd, vector<vector<int>> &dp) {
    //     // pruning

    //     // base case
    //     if (ind == nums.size()) {
    //         return 0;
    //     }
    //     //to normalize since prevInd can be -1
    //     if(dp[ind][prevInd + 1] != -1){
    //         return dp[ind][prevInd + 1];
    //     }
    //     // choices  
    //     // not take
    //     int notTake = solve(nums, ind + 1, prevInd, dp);

    //     // take
    //     int take = 0;
    //     if ((prevInd == -1) || nums[ind] > nums[prevInd]) {
    //         take = 1 + solve(nums, ind + 1, ind, dp);
    //     }
    //     return dp[ind][prevInd + 1] = max(notTake, take);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n,1);
        int maxLis=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums [i]){
                    t[i]=max(t[i],t[j] + 1);
                    maxLis=max(maxLis, t[i]);
                }
            }
        }
        return maxLis;
    }
};