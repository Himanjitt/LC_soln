class Solution {
public:
    string minWindow(string s, string t) {
        // find all the substrings
        int left = 0, right = 0;
        int index = -1, mini = INT_MAX;
        int n = s.size();
        vector<int> hash(256, 0);
        for (char ch : t) {
            hash[ch]++;
        }
        int count = 0;
        while (right < n) {
            if (hash[s[right]] > 0) {
                count++;
            }
            hash[s[right]]--;

            while (count == t.size()) {
                if (mini > right - left + 1) {
                    mini = right - left + 1;
                    index = left;
                }
                hash[s[left]]++;
                if (hash[s[left]] > 0) {
                    count--;
                }
                left++;
            }

            right++;
        }
        return (index == -1) ? "" : s.substr(index, mini);
    }
};