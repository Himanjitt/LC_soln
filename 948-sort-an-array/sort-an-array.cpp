/*
Quick Sort
    1   2  3  5
    p   s     e
   [5 , 2, 3, 1]
                 l 
              r
The idea is to find take the pivot as the first element
- first make sure all the left are small than pivot and right are
larger than pivot by swapping them
- then at last swap the pivot itself with the right position

this above will make sure the current pivot is at its correct place

and recursive solve for pivot - 1 and pivot +1

*/
class Solution {
public:
    int findPivotInd(vector<int>&nums, int start, int end){

        //next 2 lines are for random version
        int randomIndex = start + rand() % (end - start + 1);
        swap(nums[start], nums[randomIndex]);
        
        int pivot = nums[start];
        int left = start+1, right = end;

        while(left <= right){

            while(left <= end && nums[left] < pivot){
                left++;
            }

            while(right >= start && nums[right] > pivot){
                right--;
            }

            if(left <= right){
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }

        swap(nums[start], nums[right]);

        return right;
    }
    void qs(vector<int>&nums, int start, int end){
        if(start >= end){
            return;
        }

        int pivotInd = findPivotInd(nums, start, end);

        qs(nums, start, pivotInd-1);
        qs(nums, pivotInd+1, end);

    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        qs(nums,0, n-1);

        return nums;
    }
};