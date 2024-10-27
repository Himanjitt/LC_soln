class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;
        int n=nums1.size();
        int m=nums2.size();
        int ans=-1;
        for(int i=0;i<n;i++){
           st.insert(nums1[i]);
        }
        for(int i=0;i<m;i++){
            if(st.count(nums2[i])==1){
                ans=nums2[i];
                break;
            }
        }
        return ans;
    }
};