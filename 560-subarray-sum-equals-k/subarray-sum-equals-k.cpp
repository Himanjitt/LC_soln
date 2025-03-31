class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
            int remSum=sum-k;
            if(mp.find(remSum)!=mp.end()){
                count+=mp[remSum];
            }
            mp[sum]++;
        }

        return count;
    }
};
