// CHECK NOTES
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }

        int minlen = INT_MAX;
        int start_i = -1;
        
        int left = 0, right =0;
        int requiredCount = t.size();

        while(right < n){
            char ch = s[right];
            if(mp[ch] > 0){
                requiredCount--;
            }
            mp[ch]--;

            //incase we find substring in t in it
            //we will try to shrink it for min 
            while(requiredCount == 0){
                int len = right - left +1;
                //not direct min() cuz we need start index
                if(len < minlen){
                    minlen = len;
                    start_i = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0){
                    requiredCount++;
                }
                left++;
            }

            right++;
        }

        return (minlen == INT_MAX) ? "" : s.substr(start_i, minlen);
    }
};
