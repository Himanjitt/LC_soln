class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        // circular version of
        // max sum subarray of size k
        int left = nums.size() - k ;
        int right = nums.size() - k ;
        
        for(int i=0;i <= k - 1; i++){
            nums.push_back(nums[i]);
        }

        int n = nums.size();
        int maxSum = 0;
        int currSum = 0;

        while(right < n){
            currSum += nums[right];

            if(right - left + 1 > k){
                currSum -= nums[left];
                left++;
            }

            if(right - left + 1 == k) {
                maxSum = max(maxSum, currSum);
            }
            right++;
        }
        return maxSum;
    }
};

//  5,6,1,1,2,3