class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxi=nums[0];
        int maxiInd=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxiInd=i;
            }
        }

        return maxiInd;
    }
};