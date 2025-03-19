class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int left=0, right=0;
        int n=arr.size();
        unordered_map<int,int>mp;
        int ans=0;
        while(right<n){
            mp[arr[right]]++;
            while(mp.size()>2){
                mp[arr[left]]--;
                if(mp[arr[left]]==0){
                    mp.erase(arr[left]);
                }
                left++;
            }
            ans=max(ans,right-left+1);
            right++;    
        }
        return ans;
    }
};