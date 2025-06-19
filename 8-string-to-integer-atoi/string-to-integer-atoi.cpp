class Solution {
public:
    int myAtoi(string s) {
        // manage white spaces
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        s = s.substr(i);
        i = 0;
        int sign = 1;
        if (s[0] == '-') {
            sign = -1;
            i++;
        }else if(s[0] == '+'){
            sign = 1;
            i++;
        }
        int n = s.size();
        int ans = 0;
        for (i; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (ans > (INT_MAX - (s[i] - '0')) / 10) {
                    return (sign == 1) ? INT_MAX : INT_MIN;
                }
                ans = ans * 10;
                ans += s[i] - '0';
                
            } else {
                break;
            }
        }
        ans = ans * sign;

        return ans;
    }
};