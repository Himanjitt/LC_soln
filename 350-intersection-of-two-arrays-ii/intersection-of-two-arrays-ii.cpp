class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int num: nums1){
            mp[num]++;
        }

        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            if(mp.find(nums2[i]) != mp.end()){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
                if(mp[nums2[i]] == 0){
                    mp.erase(nums2[i]);
                }
            }
        }

        return ans;
    }
};