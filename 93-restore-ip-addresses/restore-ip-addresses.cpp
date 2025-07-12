/*
 i                   j 
"2 5 5 2 5 5 1 1 1 3 5"
   k
temp = 25.

*/

class Solution {
public:
    bool checkvalid(string str) {
        int n = str.length();
        if (n == 1)
            return true;
        if (n > 3 || str[0] == '0')
            return false;
        int value = stoi(str);
        if (value > 255)
            return false;
        return true;
    }

    void solve(string s, int i, int j, vector<string>& ans, string temp, int dotscount) {
        if (i > j){
            if(dotscount == 4){
                temp.pop_back();
                ans.push_back(temp);
            }
        }

        for (int k = i; k <= j ; k++) {
            if(checkvalid(s.substr(i,k-i+1)) == true){
                string part = s.substr(i, k - i +1);
                solve(s, k+1, j, ans, temp + part + '.', dotscount+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n < 4 || n > 12)
            return {};

        vector<string> ans;
        string temp = "";
        int dotscount = 0;
        solve(s, 0, n - 1, ans, temp, dotscount);
        return ans;
    }
};