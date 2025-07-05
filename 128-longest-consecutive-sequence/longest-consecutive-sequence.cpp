class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st(nums.begin(), nums.end());

        int maxi = 1;
        for(auto it: st){
            if(st.count(it - 1) == 0){
                int currlen = 1;
                while(st.count(it + 1) > 0){
                    currlen++;
                    it = it +1;
                }
                maxi = max(maxi, currlen);
            }
        }

        return maxi;
    }
};