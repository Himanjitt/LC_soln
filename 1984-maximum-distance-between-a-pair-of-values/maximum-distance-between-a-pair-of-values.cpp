class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n =nums1.size(), m= nums2.size();
        int i = 0, j =0;
        while(i<n && j<m){
            if(i <= j && nums1[i] <= nums2[j]){
                ans=max(ans, j-i);
                j++;
            }else{
                i++;
                if(i>j) j=i;
            }
        }

        return ans;


    }
};