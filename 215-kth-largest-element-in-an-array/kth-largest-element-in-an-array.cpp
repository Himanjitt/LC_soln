class Solution {
public:
    //exactly same pivot finding algo as quick sort;
    // just sign reverse for descending (since kth largest)
    int findPivotInd(vector<int>&nums, int start, int end){
        int pivot = nums[start];
        int left = start+1, right = end;

        while(left <= right){

            if(nums[left] < pivot && nums[right] > pivot){
                swap(nums[left], nums[right]);
                left++;
                right--;
            }

            if(nums[left] >= pivot){
                left++;
            }

            if(nums[right] <= pivot){
                right--;
            }
        }

        swap(nums[start], nums[right]);

        return right;
    }
    int quickSelect(vector<int> &nums, int k , int start, int end){
        if(start >= end){
            return nums[start];
        }

        int pivotInd = findPivotInd(nums, start , end);
        
        if(pivotInd == k-1){
            return nums[k-1];
        }

        if(pivotInd > k - 1){
            //search left
            return quickSelect(nums, k, start, pivotInd - 1);
        }
        else{
            //search right
            return quickSelect(nums, k, pivotInd + 1, end);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, k, 0 , n-1);
    }
};