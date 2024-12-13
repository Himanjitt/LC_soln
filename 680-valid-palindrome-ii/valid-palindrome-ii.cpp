class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.size() - 1, count = 0;

        while (start <= end) {
            if (s[start] == s[end]) {
                start++;
                end--;
                continue;
            }

            // Handle mismatch

            // Try skipping the left or right character
            return isPalindrome(s, start + 1, end) ||
                   isPalindrome(s, start, end - 1);

            return false; // More than one mismatch
        }

        return true;
    }

    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
