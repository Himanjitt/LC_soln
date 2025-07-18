class Solution {
public:
    bool isPresentAfter(string& s, char ch, int i) {
        for (int ind = i; ind < s.size(); ind++) {
            if (s[ind] == ch) {
                return true;
            }
        }

        return false;
    }

    bool isAlreadyPresent(string& ans, char ch) {
        for (int ind = 0; ind < ans.size(); ind++) {
            if (ans[ind] == ch) {
                return true;
            }
        }

        return false;
    }
    string removeDuplicateLetters(string s) {
        // the idea is to insert a character into the string if the character is
        // already there
        // if the ans.back(), the last charac is greater than current , check
        // the last is present in the future or not, if present pop and push the
        // current if current is not there already
        string ans;
        int n = s.size();
        for (int i = 0; i < n; i++) {

            // if empty
            if (ans.empty() == true) {
                ans += s[i];
                continue;
            }

            // if not empty;
            while(ans.empty() ==false && ans.back() > s[i] && isPresentAfter(s, ans.back(), i) == true &&
                isAlreadyPresent(ans, s[i]) == false) {
                ans.pop_back();
            }
            if (isAlreadyPresent(ans, s[i]) == false) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};

/*

cbacdcbc
ans = cb


*/