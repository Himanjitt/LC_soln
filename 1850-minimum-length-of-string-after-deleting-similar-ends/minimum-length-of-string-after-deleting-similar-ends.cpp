class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        int len = 0;
        while (left < right && s[left] == s[right]) {
            char ch=s[left];
            while (left < right && s[left] == ch) {
                left++;
            }
            while (left <= right && s[right] == ch) {
                right--;
            }
        }
        len = right - left + 1;

        return len;
    }
};