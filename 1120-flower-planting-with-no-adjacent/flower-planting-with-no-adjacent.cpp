class Solution {
public:
    unordered_map<int, vector<int>> adj;

    void bfs(int start, vector<int>& color) {
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            vector<bool> used(5, false);
            for (int neighbor : adj[curr]) {
                if (color[neighbor] != -1) {
                    used[color[neighbor]] = true;
                }
            }

            for (int c = 1; c <= 4; c++) {
                if (used[c]==false) {
                    color[curr] = c;
                    break;
                }
            }

            for (int neighbor : adj[curr]) {
                if (color[neighbor] == -1) {
                    q.push(neighbor);
                }
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
 
        for (auto path : paths) {
            int u = path[0];
            int v = path[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1) {
                bfs(i, color);
            }
        }

        color.erase(color.begin());
        return color;
    }
};
