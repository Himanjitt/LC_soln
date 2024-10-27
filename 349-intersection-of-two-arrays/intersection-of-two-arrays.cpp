class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1;
        unordered_set<int>st2;
        vector<int>ans;
        int m=nums1.size(),n=nums2.size();
        for(int i=0;i<m;i++){
            st1.insert(nums1[i]);
        }
        for(int i=0;i<n;i++){
            if(st1.count(nums2[i])==1){
                st2.insert(nums2[i]);
            }
        }
        for(auto it: st2){
            ans.push_back(it);
        }
        return ans;
    }
};