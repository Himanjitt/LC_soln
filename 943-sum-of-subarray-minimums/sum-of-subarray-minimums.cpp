// Count how many times each element is contributing to a subarray
// an element at index i is contributing from its pse to nse
// if length from the elemnt to its nse is "a" and to pse is "b" then the total
// no. of subarray that it will be minimum is a*b
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1000000007;
        int n = arr.size();
        long long total = 0;
        vector<int> nse(n, n);
        vector<int> pse(n, -1);
        stack<int> st;

        // nse
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                int top = st.top();
                st.pop();
                nse[top] = i;
            }
            st.push(i);
        }

        // PSE
        stack<int> st1;

        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && arr[i] < arr[st1.top()]) {
                int top = st1.top();
                st1.pop();
                pse[top] = i;
            }
            st1.push(i);
        }

        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total =
                (total + (long long)right * left % mod * arr[i] % mod) % mod;
        }
        return total;
    }
};