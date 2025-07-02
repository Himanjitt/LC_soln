class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        int totalSum = (n*(n+1) )/ 2;

        int remSum = totalSum - sum;

        if(remSum == 0) return 0;

        return remSum;
    }
};