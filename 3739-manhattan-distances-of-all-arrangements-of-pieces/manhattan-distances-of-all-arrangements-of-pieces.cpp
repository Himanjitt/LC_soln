const int MOD = 1e9 + 7;

class Solution {
public:
    int distanceSum(int m, int n, int k) {
        if (k < 2) return 0;
        int totalCells = m * n;
        if (k > totalCells) return 0;

        long long sum_h = 0;
        for (int d = 1; d < m; ++d) {
            sum_h += (long long)d * (m - d) % MOD;
        }
        sum_h = sum_h % MOD * n % MOD * n % MOD;

        long long sum_v = 0;
        for (int d = 1; d < n; ++d) {
            sum_v += (long long)d * (n - d) % MOD;
        }
        sum_v = sum_v % MOD * m % MOD * m % MOD;

        long long sum_total = (sum_h + sum_v) % MOD;

        int a = totalCells - 2;
        int b = k - 2;
        long long comb = computeCombination(a, b);

        return (sum_total * comb) % MOD;
    }

private:
    long long computeCombination(int a, int b) {
        if (b == 0) return 1;
        if (a < b) return 0;

        long long numerator = 1;
        for (int i = 0; i < b; ++i) {
            numerator = numerator * (a - i) % MOD;
        }

        long long denominator = 1;
        for (int i = 1; i <= b; ++i) {
            denominator = denominator * i % MOD;
        }

        return numerator * powMod(denominator, MOD - 2) % MOD;
    }

    long long powMod(long long x, long long y) {
        long long res = 1;
        x %= MOD;
        while (y > 0) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }
};