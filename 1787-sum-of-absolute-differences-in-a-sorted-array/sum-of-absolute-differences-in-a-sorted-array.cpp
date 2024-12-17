class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];
        
        
        // Calculate the prefix sums 
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        // Calculate absolute differences and update the result array
        for (int i = 0; i < n; i++) {
            int currentAbsoluteDiff = ((nums[i] * i) - (i==0 ? 0 : prefixSum[i-1])) + ((prefixSum[n-1]-prefixSum[i]) - (nums[i] * (n - i - 1)));
            result[i] = currentAbsoluteDiff;
        }
        
        return result;
    }
};