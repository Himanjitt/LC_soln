// sorting greedily because it is given any order, unlike normal LIS
class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> t(n,1);
        int maxLis=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j][1] < nums [i][0]){
                    t[i]=max(t[i],t[j] + 1);
                    maxLis=max(maxLis, t[i]);
                }
            }
        }
        return maxLis;
    }
};