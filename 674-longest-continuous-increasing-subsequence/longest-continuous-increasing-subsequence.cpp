class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int len =1;
        int maxlen = 1;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                len++;
                maxlen = max(maxlen, len);
            }
            else{
                len = 1;
            }
        }

        return maxlen;
    }
};