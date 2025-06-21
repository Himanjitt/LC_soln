// Greedy standard meeting start end problem
class Solution {
public:
    bool static comparator(vector<int> &a, vector<int> &b) {
        if (a[1] < b[1]) {
            return true;
        }

        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& Intervals) {
        sort(Intervals.begin(), Intervals.end(), comparator);

        int n = Intervals.size();

        int endTime = Intervals[0][1];
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (endTime <= Intervals[i][0]) {
                count++;
                endTime = Intervals[i][1];
            }
        }

        return n-count;
    }
};