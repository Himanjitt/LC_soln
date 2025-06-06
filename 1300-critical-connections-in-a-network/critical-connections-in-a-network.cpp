class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, map<int, vector<int>>& adj,
             vector<bool>& visited, vector<int>& tin, vector<int>& low,
             vector<vector<int>>& bridges) {

        visited[node] = true;
        tin[node] = low[node] = timer;
        timer++;

        for (int neighbor : adj[node]) {
            if (neighbor == parent)
                continue;
            if (visited[neighbor] == false) {
                dfs(neighbor, node, adj, visited, tin, low, bridges);
                low[node] = (min(low[node], low[neighbor]));
                if (low[neighbor] > tin[node]) {
                    bridges.push_back({node, neighbor});
                }
            } else {
                low[node] = (min(low[node], low[neighbor]));
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        map<int, vector<int>> adj;
        for (auto ele : connections) {
            int u = ele[0];
            int v = ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> bridges;
        vector<bool> visited(n, false);
        dfs(0, -1, adj, visited, tin, low, bridges);
        return bridges;
    }
};