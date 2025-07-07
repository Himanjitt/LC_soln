class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        int end = n-1;
        vector<int> ans(n);
        //fill the bigger ones at the back
        while(left <= right){
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];

            if( a > b){
                ans[end] = a;
                left ++;
            }else{
                ans[end] = b;
                right--;
            }
            end--;
        }

        return ans;
    }
};