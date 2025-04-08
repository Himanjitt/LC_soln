class Solution {
public:
    unordered_set<int> visited;

    void solve(int n, int pos, int& count) {
        if (pos > n) {
            count++;
            return;
        }

        for (int j = 1; j <= n; j++) {
            if (visited.find(j) == visited.end() &&
                (j % pos == 0 || pos % j == 0)) {
                visited.insert(j);
                solve(n, pos + 1, count);
                visited.erase(j);
            }
        }
    }
    int countArrangement(int n) {
        int count = 0;
        solve(n, 1, count);
        return count;
    }
};