// check notes
class Solution {
public:
    static bool func(string& word1, string& word2) {
        return word1.size() < word2.size();
    }

    bool isPredecessor(string& currWord, string& prevWord) {
        if (currWord.size() - prevWord.size() != 1) {
            return false;
        }
        // isSubsequece leetcode 392
        int iC = 0, jP = 0;

        while (iC < currWord.size()) {
            if (prevWord[jP] == currWord[iC]) {
                jP++;
                iC++;
            } else {
                iC++;
            }
        }
        if (jP == prevWord.size()) {
            return true;
        }
        return false;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        // custom sorting based on length
        vector<int> dp(n,1);
        sort(words.begin(), words.end(), func);

        // standard optimized way
        int maxlen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j< i; j++) {

                if (isPredecessor(words[i], words[j]) == true) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxlen = max(maxlen, dp[i]);
                }
            }
        }
        return maxlen;
    }
};