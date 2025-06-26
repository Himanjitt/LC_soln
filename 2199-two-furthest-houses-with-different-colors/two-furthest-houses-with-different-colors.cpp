class Solution {
public:
    int maxDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        //greedily maximum distance is only possible 
        //from start or end
        int maxDistLeft = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[0])
                maxDistLeft = max(maxDistLeft, i - 0);
        }

        int maxDistRight = 0;
        for(int i=n-2; i>= 0; i--){
            if(nums[i] != nums[n-1])
                maxDistLeft = max(maxDistLeft, n-1 - i);
        }

        return max(maxDistLeft, maxDistRight);
    }
};