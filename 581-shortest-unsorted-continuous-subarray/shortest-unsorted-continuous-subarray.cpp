class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1) return 0;

        int maxi = INT_MIN, mini = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            
            if (i == 0) {
                if (nums[i] > nums[i + 1]) {
                    maxi = max(maxi, nums[i]);
                    mini = min(mini, nums[i]);
                }
                
            }
            else if (i == n - 1) { 
                if (nums[i - 1] > nums[i]) {
                    maxi = max(maxi, nums[i]);
                    mini = min(mini, nums[i]);
                }
                
            } 
            else if(nums[i - 1] > nums[i] || nums[i] > nums[i + 1]){
                maxi = max(maxi, nums[i]);
                mini = min(mini, nums[i]);
            }
        }
        if(maxi==INT_MIN || mini==INT_MAX) return 0;
        
        int i,j;
        for(i=0;i<n;i++){
            if(nums[i]>mini){
                break;
            }
        }
        for(j=n-1;j>=0;j--){
            if(nums[j]<maxi){
                break;
            }
        }

        return j-i+1;
    }
};