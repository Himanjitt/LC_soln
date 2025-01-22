class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        int m = n / 2;
        vector<vector<long long>> prev_dp(3, vector<long long>(3, LLONG_MAX));

        int left = 0;
        int right = n - 1;
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                if (a != b) {
                    prev_dp[a][b] = cost[left][a] + cost[right][b];
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            left = i;
            right = n - 1 - i;
            vector<vector<long long>> curr_dp(3, vector<long long>(3, LLONG_MAX));

            for (int a = 0; a < 3; ++a) {
                for (int b = 0; b < 3; ++b) {
                    if (a == b) continue;
                    long long current_cost = cost[left][a] + cost[right][b];

                    for (int prev_a = 0; prev_a < 3; ++prev_a) {
                        for (int prev_b = 0; prev_b < 3; ++prev_b) {
                            if (prev_a == a || prev_b == b) continue;
                            if (prev_dp[prev_a][prev_b] == LLONG_MAX) continue;

                            long long total = prev_dp[prev_a][prev_b] + current_cost;
                            if (total < curr_dp[a][b]) {
                                curr_dp[a][b] = total;
                            }
                        }
                    }
                }
            }

            prev_dp.swap(curr_dp);
        }

        long long ans = LLONG_MAX;
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                if (a != b) {
                    ans = min(ans, prev_dp[a][b]);
                }
            }
        }

        return ans;
    }
};