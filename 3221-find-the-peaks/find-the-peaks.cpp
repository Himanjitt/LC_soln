class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=1;i<=n-2;i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};