class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int,int>mp1,mp2;

        for(auto n: nums1){
            mp1[n]++;
        }
        for(auto n: nums2){
            mp2[n]++;
        }
        vector<int> ans;
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(mp2.count(nums1[i])>0){
                count1+=mp2[nums1[i]];
                mp2[nums1[i]]=0;
            }
        }
        for(int i=0;i<m;i++){
            if(mp1.count(nums2[i])>0){
                count2+=mp1[nums2[i]];
                mp1[nums2[i]]=0;
            }
        }
        ans.push_back(count2);
        ans.push_back(count1);

        return ans;
    }
};