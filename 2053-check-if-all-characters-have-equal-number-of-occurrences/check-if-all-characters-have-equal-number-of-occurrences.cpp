class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;

        for(auto i: s){
            mp[i]++;
        }

        int freq=mp[s[0]];

        for(auto it: mp){
            if(it.second!=freq){
                return false;
            }
        }
        return true;
    }
};