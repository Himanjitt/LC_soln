class Solution {
public:
    unordered_map<int, vector<int>> adjlist;

    void dfs(int i,vector<int> &visited, bool& ans, int destination) {
        if (visited[i] == 1 || ans == true) {
            return;
        }
        if (i == destination) {
            ans = true;
            return;
        }
        visited[i] = 1;

        for (auto neighbor : adjlist[i]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, visited,ans, destination);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<int> visited(n, 0);

        bool ans = false;
        int i=source;
        dfs(i, visited,ans, destination);
        if (ans == true) {
            return true;
        }

        return ans;
    }
};