class Solution {
public:
    unordered_map<int, vector<int>> adj;

    bool bfs(int index, vector<int>& color) {
        if (color[index] == -1) {
            color[index] = 0;
            queue<int> q;
            q.push(index);

            while (q.empty() == false) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // here we will assume the dislike couples as and edge
        // so we will create a graph
        for (auto dislike : dislikes) {
            int u = dislike[0];
            int v = dislike[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (bfs(i, color) == false) {
                return false;
            }
        }

        return true;
    }
};