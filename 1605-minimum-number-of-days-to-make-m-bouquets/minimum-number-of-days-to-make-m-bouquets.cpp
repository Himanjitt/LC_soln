class Solution {
public:
    bool isValid(vector<int> nums, int k, int m, int mid){
        long long flowers = 0;
        int bouquets = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] <= mid){
                flowers++;
            }else{
                bouquets += flowers/k;
                flowers=0; 
            }
        }
        bouquets += flowers/k;
        if(bouquets >= m){
            return true;
        }
        return false;
        
    }
    int minDays(vector<int> nums, int m, int k) {
        // search space is between min (nums) && max(nums)
        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());

        int ans=-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if(isValid(nums, k, m, mid) == true){
                ans = mid;
                end = mid -1;
            }else{
                start = mid +1;
            }
        }

        return ans;
    }
};