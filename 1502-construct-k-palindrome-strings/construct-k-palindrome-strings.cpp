class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if(s.size()==k) return true;

        if(s.size()<k) return false;
        unordered_map<int,int>mp;
        for(char ch: s){
            mp[ch]++;
        }
        int oddCount=0;
        for(auto it: mp){
            if(it.second%2==1){
                oddCount++;
            }
        }

        if(oddCount<=k) return true;

        return false;

    }
};