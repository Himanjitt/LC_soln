class Solution {
public:
    long long sumSubarrayMaxs(vector<int>& arr) {

        int n = arr.size();
        long long total = 0;
        vector<int> nge(n, n);
        vector<int> pge(n, -1);
        stack<int> st2;

        // nge
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && arr[i] >= arr[st2.top()]) {
                nge[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }

        // PgE
        stack<int> st3;

        for (int i = n - 1; i >= 0; i--) {
            while (!st3.empty() && arr[i] > arr[st3.top()]) {
                pge[st3.top()] = i;
                st3.pop();
            }
            st3.push(i);
        }

        for (int i = 0; i < n; i++) {
            int left = i - pge[i];
            int right = nge[i] - i;
            total = (total + (long long)right * left * arr[i]);
        }
        return total;
    }

    long long sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        long long total = 0;
        vector<int> nse(n, n);
        vector<int> pse(n, -1);
        stack<int> st;

        // nse
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // PSE
        stack<int> st1;

        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && arr[i] < arr[st1.top()]) {
                pse[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }

        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (long long)right * left * arr[i]);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long ans = sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
        return ans;
    }
};