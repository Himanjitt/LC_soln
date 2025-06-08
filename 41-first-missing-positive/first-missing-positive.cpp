class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mini=max(mini,nums[i]);
        }
        if(mini <= 0) return 1;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=1;i< mini;i++){
            if(st.find(i) == st.end()){
                return i;
            }
        }
        return -1;
    }
};