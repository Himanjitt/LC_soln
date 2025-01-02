class Solution {
public:
    int isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return 1;
        }
        return 0;
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n);
        prefix[0] = isVowel(words[0][0]) && isVowel(words[0].back());
        for (int i = 1; i < n; i++) {
            int current = isVowel(words[i][0]) && isVowel(words[i].back());
            prefix[i] = prefix[i - 1] + current;
        }
        vector<int> ans;
        for (auto q : queries) {
            int left = q[0], right = q[1];
            int curr = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
            ans.push_back(curr);
        }
        return ans;
    }
};