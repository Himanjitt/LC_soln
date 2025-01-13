class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;

        for(char ch: s){
            mp[ch]++;
        }
        int ans=0;
        
        for(auto it: mp){
            while(it.second>=3){
                it.second-=2;
            }
            ans+=it.second;
        }

        return ans;
    }
};