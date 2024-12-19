class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto num: nums){
            mp[num]++;
        }
        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==2){
                ans=ans^nums[i];
                mp[nums[i]]--;
            }
        }
        
        return ans;
    }
};