class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        char lastSeenOp = '+';
        int num = 0;
        for (int i = 0; i < n; i++) {

            if (isdigit(s[i]) == true) {
                num = 0;
                while(i<n && isdigit(s[i]) == true){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
            }
            if ((isdigit(s[i]) == false && s[i] != ' ') || i == n - 1) {
                if (lastSeenOp == '+') {
                    st.push(num);
                }
                else if (lastSeenOp == '-') {
                    st.push(-num);
                }
                else if (lastSeenOp == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } 
                else if(lastSeenOp == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                lastSeenOp = s[i];
               
            }
        }
        int ans = 0;
        while (st.empty() == false) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};