class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 && j<nums.size()){
                ans[j]=nums[i];
                j+=2;
            }
        }
        j=1;
         for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0 && j<nums.size()){
                ans[j]=nums[i];
                j+=2;
            }
        }

        return ans;
    }
};