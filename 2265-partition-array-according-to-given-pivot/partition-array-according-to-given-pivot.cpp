class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        int n=nums.size();
        int i=0;
        vector<bool>indexTrack(n,0);
        for( i=0;i<n;i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
                indexTrack[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                ans.push_back(nums[i]);
                indexTrack[i]=1;
            }
        }
        int j=0;
        while(j<n){
            if(indexTrack[j]==1){
                j++;
                continue;
            }
            ans.push_back(nums[j]);
            j++;
        }
        return ans;
    }
};