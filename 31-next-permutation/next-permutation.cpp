class Solution {
public:
    // 1)Find breakpoint from the end 
    // 2)Swap the breakpoint value with rightmost value which is greater 
    // greater than breakpoint value
    // 3) reverse from breakpoint+1 to end 
    void nextPermutation(vector<int>& nums) {
        //find the breaking point
        int n = nums.size();
        int breakInd=-1;
        for(int i = n-2;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                breakInd = i;
                break;
            }
        }
        if(breakInd == -1){
            reverse(nums.begin(), nums.end());
            return ;
        }
        for(int i= n-1;i>=breakInd;i--){
            if(nums[breakInd] < nums[i]){
                swap(nums[breakInd], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + breakInd + 1, nums.end());
    }
};