class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if(k == 1) return *max_element(nums.begin(), nums.end());
        long long maxSum = 0;
        int left = 0, right = 0;
        unordered_map<int,int> mp;
        
        long long currSum =0;
        while(right < n){
              
            mp[nums[right]]++;
            currSum += nums[right];

            if((right - left +1)> k) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                currSum -= nums[left];
                left++;
            }
            if((right - left + 1) == k && mp.size() >= m){
                maxSum= max(maxSum, currSum);
            }
            right++;
        }

        return maxSum;
    }
};