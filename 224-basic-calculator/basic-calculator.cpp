class Solution {
public:
    int calculate(string s) {
        // value, sign before opening bracket
        stack<pair<int, int>> st;
        int n = s.size();
        int sum = 0;
        int sign = 1;
        for (int i = 0; i < n; i++) {

            if (s[i] >= '0' && s[i] <= '9') {
                int num =0;
                while (i < n && (s[i] >= '0' && s[i] <= '9')) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = 1;
            }

            else if (s[i] == '(') {
                // save current state of sum , sign
                st.push({sum, sign});
                // reset values, for inside calculation
                sum = 0;
                sign = 1;
            }

            else if (s[i] == ')') {
                sum = st.top().first + (st.top().second * sum);
                st.pop();
            }

            else if (s[i] == '-') {
                sign = (-1 * sign);
            }
        }
        return sum;
    }
};