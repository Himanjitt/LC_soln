class Solution {
public:
    int m, n;
    typedef pair<int, pair<int, int>> P;

    bool isValid(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }

        return true;
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            pair<int, pair<int, int>> node = pq.top();
            pq.pop();

            int dis = node.first;
            int x = node.second.first;
            int y = node.second.second;

            if (x == m - 1 && y == n - 1) {
                return dis;
            }
            for (auto ele : dir) {
                int x_new = ele.first + x;
                int y_new = ele.second + y;

                if (isValid(x_new, y_new)) {
                    int newEffort =
                        max(dis, abs(grid[x_new][y_new] - grid[x][y]));
                    if (newEffort < distance[x_new][y_new]) {
                        distance[x_new][y_new] = newEffort;
                        pq.push({distance[x_new][y_new], {x_new, y_new}});
                    }
                }
            }
        }
        return -1;
    }
};