class Solution {
public:
    string countAndSay(int n) {
        // base case
        if (n == 1)
            return "1";

        // call
        string prev = countAndSay(n - 1);

        int count = 1, i = 1;
        string res = "";
        for (i = 1; i < prev.size(); i++) {
            if (prev[i] == prev[i - 1]) {
                count++;
            } else {
                res += to_string(count);
                count = 1;
                res += prev[i - 1];
            }
        }
        res += to_string(count);
        count = 1;
        res += prev[i - 1];

        return res;
    }
};

