class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    int m, n;
    bool isSafe(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        return true;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // dijsktra on grid
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        distance[0][0] = grid[0][0];
        vector<vector<int>> dirs={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int dis = node.first;
            int x = node.second.first;
            int y = node.second.second;

            if (x == m - 1 && y == n - 1) {
                if (distance[x][y] < health) {
                    return true;
                } else
                    return false;
            }
            for (auto dir : dirs) {
                int x_new = x + dir[0];
                int y_new = y + dir[1];

                if (isSafe(x_new, y_new)) {
                    if (dis + grid[x_new][y_new] < distance[x_new][y_new]) {
                        distance[x_new][y_new] = dis + grid[x_new][y_new];
                        pq.push({distance[x_new][y_new], {x_new, y_new}});
                    }
                }
            }
        }

        return false;
    }
};