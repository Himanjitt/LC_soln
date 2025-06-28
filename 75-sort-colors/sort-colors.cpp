class Solution {
public:
    void sortColors(vector<int>& nums) {
        //i represents 0
        //j represent 1
        //k represents 2
        int i=0, j=0, k=nums.size()-1;

        while(j<=k){
            if(nums[j] == 1){
                j++;
            }
            else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k--;
            }
            else{
                swap(nums[j],nums[i]);
                i++;
                j++;
            }
        }
    }
};