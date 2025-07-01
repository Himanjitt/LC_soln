class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return *max_element(nums.begin(), nums.end());
        long long maxSum = 0;
        int left = 0, right = 0;
        unordered_set<int> st;
        
        long long currSum =0;
        while(right < n){
            while(st.find(nums[right]) != st.end()){
                st.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }   
            st.insert(nums[right]);
            currSum += nums[right];

            if((right - left +1)> k) {
                st.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }

            if((right - left + 1) == k){
                maxSum= max(maxSum, currSum);
            }
            right++;
        }

        return maxSum;
    }
};