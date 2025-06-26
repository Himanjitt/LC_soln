class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[j] > nums[i])
                    ans = max(ans, nums[j] - nums[i]);
            }
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};