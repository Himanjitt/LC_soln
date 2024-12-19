class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for (auto ch : chars) {
            mp[ch]++;
        }

        int ans = 0;
        
        for (auto word : words) {
            unordered_map<char,int>temp=mp;
            bool flag=0;
            for (int i = 0; i < word.size(); i++) {
                if (temp[word[i]] >0) {
                   temp[word[i]]--;
                }else{
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                ans+=word.size();
        }

        return ans;
    }
};