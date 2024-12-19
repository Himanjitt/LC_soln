class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<t.size();i++){
            mp[t[i]]=i;
        }
        int sum=0;
        for(int i=0;i<s.size();i++){
            int second_index=mp[s[i]];
            sum+=abs(second_index - i);
        }

        return sum;
    }
};