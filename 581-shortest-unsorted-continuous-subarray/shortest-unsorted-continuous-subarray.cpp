class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int>nums2(nums.begin(),nums.end());
        sort(nums2.begin(),nums2.end());
        if(nums2==nums) return 0;
        int i=0,j=0;
        for(i=0;i<n;i++){
            if(nums2[i]!=nums[i]){
                break;
            }
        }
        for(j=n-1;j>=0;j--){
            if(nums2[j]!=nums[j]){
                break;
            }
        }

        return j-i+1;
    }
};