class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Step 1: Initialize BFS with all land cells
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = 1; // Mark land cells as visited
                }
            }
        }

        // If all cells are land or water, return -1
        if (q.empty() || q.size() == n * n) {
            return -1;
        }

        int max_distance = -1;

        // Step 2: Perform BFS
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                // Check bounds and whether the cell is unvisited water
                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    !visited[nx][ny] && grid[nx][ny] == 0) {
                    visited[nx][ny] =
                        visited[x][y] + 1; // Mark as visited and store distance
                    max_distance = max(max_distance, visited[nx][ny] - 1);
                    q.push({nx, ny});
                }
            }
        }

        return max_distance;
    }
};