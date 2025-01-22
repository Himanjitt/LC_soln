class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> left_max(n, -1), right_max(n, n);
        vector<int> left_min(n, -1), right_min(n, n);
        stack<int> st;

        // Compute left_max using monotonic stack
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            left_max[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            right_max[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Compute left_min using monotonic stack
        st = stack<int>();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            left_min[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            right_min[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long total = 0;

        for (int i = 0; i < n; ++i) {
            // Calculate count_max[i]
            int L_max = left_max[i] + 1;
            int R_max = right_max[i] - 1;
            int s_start_max = max(L_max, i - k + 1);
            int s_upper_max = min(i, R_max - k + 1);

            long long first_part_max = 0;
            if (s_start_max <= s_upper_max) {
                long long a = s_start_max, b = s_upper_max;
                long long sum_s = (b * (b + 1) - (a - 1) * a) / 2;
                first_part_max = sum_s + (k - i) * (b - a + 1);
            }

            long long c_max = s_upper_max + 1;
            long long d_max = i;
            c_max = max(c_max, (long long)L_max);
            d_max = min(d_max, (long long)i);
            long long second_part_max = 0;
            if (c_max <= d_max) {
                second_part_max = (R_max - i + 1) * (d_max - c_max + 1);
            }
            long long count_max = first_part_max + second_part_max;

            // Calculate count_min[i]
            int L_min = left_min[i] + 1;
            int R_min = right_min[i] - 1;
            int s_start_min = max(L_min, i - k + 1);
            int s_upper_min = min(i, R_min - k + 1);

            long long first_part_min = 0;
            if (s_start_min <= s_upper_min) {
                long long a = s_start_min, b = s_upper_min;
                long long sum_s = (b * (b + 1) - (a - 1) * a) / 2;
                first_part_min = sum_s + (k - i) * (b - a + 1);
            }

            long long c_min = s_upper_min + 1;
            long long d_min = i;
            c_min = max(c_min, (long long)L_min);
            d_min = min(d_min, (long long)i);
            long long second_part_min = 0;
            if (c_min <= d_min) {
                second_part_min = (R_min - i + 1) * (d_min - c_min + 1);
            }
            long long count_min = first_part_min + second_part_min;

            total += nums[i] * (count_max + count_min);
        }

        return total;
    }
};