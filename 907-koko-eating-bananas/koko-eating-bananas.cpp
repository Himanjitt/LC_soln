class Solution {
public:
    bool isValid(vector<int> &nums, int h, int mid){
        long long hours =0;
        for(int i=0;i<nums.size();i++){
            hours += ceil((double) nums[i] / mid) ; 
        }
        if(hours <= h){
            return true;
        }

        return false;
    }
    int minEatingSpeed(vector<int> nums, int h) {
        // probable answer space is
        // he can eat at max max(nums) in an hourly
        // min of 1
        int start = 1, end = *max_element(nums.begin(), nums.end());
        int ans = end;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(nums, h, mid) == true) {
                ans = mid;
                end = mid-1;
            } else {
                start = mid +1;
            }
        }
        return ans;
    }
};