class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n =nums1.size(), m= nums2.size();
        int i = 0, j =0;
        while(i<n && j<m){
            if(nums1[i] > nums2[j]){
                i++;
            }else{
                ans=max(ans, j-i);
                j++;
            }
        }

        return ans;


    }
};