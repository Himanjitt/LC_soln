class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        // char to frequency
        unordered_map<char, int> mp;
        int maxlen = 1;
        int maxFreq = 0;
        int left = 0, right = 0;
        while (right < n) {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);
            //See Hint the main condition for valid window is
            // the window size - maxfreq in the window should be > k
            while ((right - left + 1) - maxFreq > k) {
                mp[s[left]]--;
                if (mp[s[left] < 0]) {
                    mp.erase(mp[s[left]]);
                }
                left++;
            }
            int len = right - left + 1;
            maxlen = max(maxlen, len);
            right++;
        }

        return maxlen;
    }
};


/*



*/