class Solution {
public:
    bool isPresent(char ch, string& ans) {
        for (char ele : ans) {
            if (ele == ch) {
                return true;
            }
        }

        return false;
    }
    bool isPresentAfter(int i, string s, char ch) {
        for (int j = i; j < s.size(); j++) {
            if (s[j] == ch) {
                return true;
            }
        }

        return false;
    }
    string smallestSubsequence(string s) {
        string ans;

        for (int i = 0; i < s.size(); i++) {

            while (ans.empty() == false && ans.back() > s[i] &&
                   isPresentAfter(i, s, ans.back()) == true &&
                   isPresent(s[i], ans) == false) {
                ans.pop_back();
            }
            if (isPresent(s[i], ans) == false)
                ans.push_back(s[i]);
        }

        return ans;
    }
};