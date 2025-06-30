class Solution {
public:
    bool isValid(vector<int> &nums, double hour, int mid){
        double currHours =0;
        int i=0;
        for( i=0;i<nums.size()-1;i++){
            currHours += ceil((double) nums[i] / mid) ; 
        }
        currHours += (double) nums[nums.size()-1] / mid; //last one in float
        if(currHours <= hour){
            return true;
        }

        return false;
    }
    int minSpeedOnTime(vector<int>& nums, double hour) {
        // probable answer space is

        int start = 1, end = 1e7;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(nums, hour, mid) == true) {
                ans = mid;
                end = mid-1;
            } else {
                start = mid +1;
            }
        }
        return ans;
    }
};