/*
    l           r            
[2, 1, 4, 7, 3, 2, 5]

*/
class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        int maxlen =0;

        for(int i=1;i<n-1;i++){

            //if mountain found
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                int left = i-1, right = i+1;
                //go to start of mountain
                while(left-1 >=0 && nums[left] > nums[left -1]){
                    left--;
                }
                //go to end of mountain
                while(right + 1 < n && nums[right] > nums[right+1]){
                    right++;
                }
                maxlen = max(maxlen, right - left +1);
            }
        }

        return maxlen;
    }
};

