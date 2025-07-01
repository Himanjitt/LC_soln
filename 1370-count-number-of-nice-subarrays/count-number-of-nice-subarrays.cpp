//SAME here just replace odd with 1 and even with 0, 
//then k odd number ,mean k 1s mean sum = k
// SAME as LEETCODE 560
//CHECK NOTES
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // Replace odd with 1 and even with 0
        for (int i=0;i<nums.size();i++){
            if (nums[i] % 2)
                nums[i] = 1;
            else
                nums[i] = 0;
        }
        unordered_map<int, int> mp;      
        mp[0] = 1;
        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            sum +=nums[i];

            int rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[sum]++;
        }
        return count;
    }
};
