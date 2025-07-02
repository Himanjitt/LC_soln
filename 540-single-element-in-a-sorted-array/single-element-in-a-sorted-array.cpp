//CHECK NOTES , The pairs on the left side of single =>(even , odd) pos
// pairs on the right side of single =>(odd, even) pos 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int start = 0, end = nums.size() -1;

        while(start <= end){

            int mid = start + (end - start)/2;
            
            if(mid == 0 && nums[mid] != nums[mid +1]){
                return nums[mid];
            }
            else if (mid == n-1 && nums[mid-1] != nums[mid]){
                return nums[mid];
            }
            else if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

            if((mid % 2 == 0 && nums[mid-1] == nums[mid]) ||
                (mid % 2 != 0 && nums[mid] == nums[mid+1])){
                end = mid -1;
            }
            else{
                start = mid +1;
            }
        }
        return -1;
    }
};