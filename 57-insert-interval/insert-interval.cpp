//CHECK NOTES
// EXACTLY SAME LIKE merge intervals(LC 56) here we just 
// 1 more step first insert , then again merge
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end()); // Sort based on start times
        vector<vector<int>> ans;

        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (ans.empty()) {
                ans.push_back(intervals[i]);
            } else {
                vector<int>& v = ans.back();
                if (v[1] >= intervals[i][0]) {
                    v[0] = min(v[0], intervals[i][0]);
                    v[1] = max(v[1], intervals[i][1]);
                } else {
                    ans.push_back(intervals[i]);
                }
            }
        }

        return ans;
    }
};

/*

[1,3][6,9]    [2,5]

ans => [1,5][6,9]


*/