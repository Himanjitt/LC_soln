class Solution {
public:
    int count = 0;
    void merge(vector<int> &nums, int start, int mid, int end){
        int left = start, right = mid+1;
        for(int i = start ; i<= mid;i++){
            while(right <= end && nums[i] > 2LL * nums[right]){
                right++;
            }
            count = count + (right - (mid +1));  

        }

        //normal merging
        vector<int>temp;
        left = start, right = mid+1;
        while(left <= mid && right <= end){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= end ){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = 0;i<temp.size();i++){
            nums[start + i] = temp[i];
        }
    }

    void mergeSort(vector<int>&nums, int start, int end){
        if(start >= end){
            return;
        }
        int mid = start + (end - start)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);

        merge(nums, start, mid, end);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0 , nums.size()-1);
        return count;
    }
};