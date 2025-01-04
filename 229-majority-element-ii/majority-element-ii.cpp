class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int F=n/3;

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto it: mp){
            if(it.second > F){
                ans.push_back(it.first);
            }
        }

        return ans;

    }
};