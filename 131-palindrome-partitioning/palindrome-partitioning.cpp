// MCM DP // Partition DP
class Solution {
public:
    int n;
    bool isPali(int start, int end, string& s) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, string& s, int i,
               vector<string> temp) {
        if (i >= s.size()) {
            ans.push_back(temp);
        }

        for (int k = i; k < n; k++) {
            if (isPali(i, k, s)) {
                temp.push_back(s.substr(i, k - i + 1));
                solve(ans, s, k + 1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans, s, 0, temp);
        return ans;
    }
};