class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        //presum to index
        unordered_map<int,int>mp;
        mp[0] = -1;
        int maxlen=0;
        int sum=0;

        for(int i=0;i<n;i++){
            sum += (nums[i]==0) ? -1:1;

            //note here target is k=0
            int remSum = sum - 0;
            if(mp.find(remSum) != mp.end()){
                int len = i - mp[remSum];
                maxlen= max(maxlen, len);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }

        return maxlen;
    }
};