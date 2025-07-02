class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start =0, end = n-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target)
                return true;
            
            //shrink search space in case duplicates
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
                continue;
            }

            //left sorted 
            if(nums[start] <= nums[mid]){
                if(target >= nums[start] && target <= nums[mid]){
                    end = mid -1;
                }else{
                    start = mid +1;
                }
            }
            // right sorted
            else{
                if(target >= nums[mid] && target <= nums[end]){
                    start = mid +1;
                }else{
                    end = mid -1;
                }
            }
        }

        return false;
    }
};