class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        int m = nums.size();
        long long n = m * m;

        long long SN = (n * (n + 1)) / 2;

        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        long long S = 0, S2 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                S += nums[i][j];
                S2 += (long long)nums[i][j] * (long long)nums[i][j];
            }
        }
        //x-y
        long long val1 = S - SN;
        //(x-y)(x+y)
        long long val2 = S2 - S2N;

        //(x+y)
        val2 = val2 / val1;

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};