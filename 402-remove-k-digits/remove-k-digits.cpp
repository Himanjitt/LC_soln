class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st;
        int n = nums.size();
        if (n == k) return "0";
        for (int i = 0; i < n; i++) {
            while (st.empty() == false && nums[i] < st.top() && k > 0) {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        // for the edge case of if k>0
        while (k>0 && st.empty()==false) {
            st.pop();
            k--;
        }

        // for the edge case of removal of leading zeros
        string ans;
        while (st.empty() == false) {
            ans.push_back(st.top());
            st.pop();
        }
        int size = ans.size();
        int ind = size - 1;
        while (ind>=0 && ans[ind] == '0') {
            ans.pop_back();
            ind--;
        }
        reverse(ans.begin(), ans.end());

        return (ans.size()==0) ? "0": ans;
    }
};