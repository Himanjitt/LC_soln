/*

a : 0
b : 0
c : 0
               r
s = "e b a b a c d", p = "abc"
           l
*/

class Solution {
public:
    bool allzero(unordered_map<char, int> &mp){
        for(auto it: mp){
            if(it.second != 0){
                return false;
            }
        }

        return true;
    }
    vector<int> findAnagrams(string txt, string pat) {
        unordered_map<char, int> mp;
        for (auto ch : pat) {
            mp[ch]++;
        }

        int n = txt.size();
        int left = 0, right = 0;
        int k = pat.size();
        vector<int> ans;

        while (right < n) {
            char ch = txt[right];

            if(mp.find(ch) != mp.end()){
                mp[ch]--;
            }

            if(right - left + 1 == k){
                if(allzero(mp) == true){
                    ans.push_back(left);
                }

                if(mp.find(txt[left]) != mp.end()){
                    mp[txt[left]]++;
                }
                left++;
            }

            right++;
            
        }

        return ans;
    }
};