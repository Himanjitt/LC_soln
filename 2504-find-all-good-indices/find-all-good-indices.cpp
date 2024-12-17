class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
       int n=nums.size();
        vector<int>decreasing(n,0);
        vector<int>increasing(n,0);
        vector<int> ans;

        for(int i=1;i<n;i++){
            if(nums[i-1]>=nums[i]){
                decreasing[i]=decreasing[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                increasing[i]=increasing[i+1]+1;
            }
        }

        for(int i=k;i<n-k;i++){
            if(decreasing[i-1]>=k-1 && increasing[i+1]>=k-1){
                ans.push_back(i);
            }
        }
        return ans; 
    }
};